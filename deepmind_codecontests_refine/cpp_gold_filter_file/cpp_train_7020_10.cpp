#include <bits/stdc++.h>
using namespace std;
int n, f1, f2;
int f[100005];
int s[100005];
bool ans[100005];
vector<int> an;
bool chk[100005];
vector<int> ad[100005];
void dfs(int now, int height) {
  chk[now] = true;
  int ff1 = f1, ff2 = f2;
  if (height % 2 == 1) {
    if ((f1 + f[now]) % 2 != s[now]) f1++, an.push_back(now);
  }
  if (height % 2 == 0) {
    if ((f2 + f[now]) % 2 != s[now]) f2++, an.push_back(now);
  }
  for (int i = 0; i < ad[now].size(); i++)
    if (!chk[ad[now][i]]) {
      dfs(ad[now][i], height + 1);
    }
  f1 = ff1, f2 = ff2;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int in1, in2;
    scanf("%d %d", &in1, &in2);
    ad[in1].push_back(in2);
    ad[in2].push_back(in1);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  dfs(1, 0);
  printf("%d\n", an.size());
  sort(an.begin(), an.end());
  for (int i = 0; i < an.size(); i++) printf("%d\n", an[i]);
  return 0;
}
