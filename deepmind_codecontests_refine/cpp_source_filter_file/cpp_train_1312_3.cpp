#include <bits/stdc++.h>
using namespace std;
const int M = 0;
const int N = 1000010;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
int n, k, cnt = 0, ans = 0;
char a[N] = {0};
int st[30] = {0}, ed[30] = {0}, t1[N] = {0}, t2[N] = {0};
int main(void) {
  scanf("%d%d%s", &n, &k, a + 1);
  for (int i = 1; i <= n; ++i) {
    int p = a[i] - 'A' + 1;
    if (!st[p]) st[p] = i;
    ed[p] = i;
  }
  for (int i = 1; i <= 26; ++i)
    if (st[i]) {
      t1[st[i]] = 1, t2[ed[i]] = -1;
    }
  for (int i = 1; i <= n; ++i)
    if (t1[i]) {
      cnt += t1[i];
      ans = max(cnt, ans);
      cnt += t2[i];
    }
  cout << (ans > k ? "YES" : "NO") << endl;
  return 0;
}
