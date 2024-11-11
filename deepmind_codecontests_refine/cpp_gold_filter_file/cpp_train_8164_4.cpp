#include <bits/stdc++.h>
using namespace std;
char in[100005];
int f[100005], ans[100005];
vector<int> vans;
void build_KMP(int n, char *s, int *f) {
  f[0] = -1, f[1] = 0;
  for (int i = 2; i <= n; i++) {
    int w = f[i - 1];
    while (w >= 0 && s[w + 1] != s[i]) w = f[w];
    f[i] = w + 1;
  }
}
int main() {
  int len;
  scanf("%s", in + 1);
  len = strlen(in + 1);
  build_KMP(len, in, f);
  fill(ans, ans + 100005, 1);
  for (int i = len; i > 0; i--) {
    ans[f[i]] += ans[i];
  }
  int now = len;
  while (1) {
    vans.push_back(now);
    now = f[now];
    if (now == 0) break;
  }
  printf("%d\n", vans.size());
  for (int i = vans.size() - 1; i >= 0; i--) {
    printf("%d %d\n", vans[i], ans[vans[i]]);
  }
}
