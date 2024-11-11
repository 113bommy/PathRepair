#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int a[(1 << (20 + 1)) + 10];
vector<int> ans;
int getid(int k) {
  if (a[k << 1] == 0 && a[(k << 1) + 1] == 0)
    return k;
  else if (a[k << 1] > a[(k << 1) + 1])
    return getid(k << 1);
  else
    return getid((k << 1) + 1);
}
void dfs(int k) {
  if (a[k << 1] == 0 && a[(k << 1) + 1] == 0) {
    a[k] = 0;
    return;
  } else if (a[k << 1] > a[(k << 1) + 1])
    a[k] = a[k << 1], dfs(k << 1);
  else
    a[k] = a[(k << 1) + 1], dfs((k << 1) + 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, g;
    scanf("%d%d", &h, &g);
    for (int i = 1; i <= 1 << (h + 1); i++) a[i] = 0;
    ans.clear();
    for (int i = 1; i <= (1 << h) - 1; i++) scanf("%d", &a[i]);
    int limit = (1 << g) - 1;
    for (int i = 1; i <= (1 << g) - 1; i++) {
      while (getid(i) > limit) {
        ans.push_back(i);
        dfs(i);
      }
    }
    long long sum = 0;
    for (int i = 1; i <= (1 << g) - 1; i++) sum += a[i];
    printf("%lld\n", sum);
    for (int i = 0; i < ans.size(); i++)
      printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
  }
  return 0;
}
