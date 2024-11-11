#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100], b[100], all, ans, c[100], tot, cc[100];
int ck[10][1 << 9];
int d[1 << 9];
int cheak(long long t, int set) {
  for (int i = 0; i < n; i++)
    if ((1 << i) & set)
      if (t % a[i + 1] != 0)
        return 0;
      else
        t = t / a[i + 1];
  return 1;
}
void ready() {
  cin >> n;
  all = (1 << n) - 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    long long t = a[i];
    c[i] = 1;
    for (int j = 2, lim = sqrt(t); j <= lim; j++)
      if (t % j == 0) {
        while (t % j == 0) {
          t /= j;
          c[i]++;
        }
      }
    if (t > 1) c[i]++;
    if (a[i] == t)
      cc[i] = 0;
    else
      cc[i] = 1;
  }
  ans = 1 << 29;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= all; j++) {
      ck[i][j] = cheak(a[i], j);
    }
  for (int i = 0; i <= all; i++)
    for (int j = 1; j <= n; j++)
      if ((1 << (j - 1)) & i) d[i] += c[j] + cc[j];
}
void dfs(int dep, int set, long long tot) {
  if (dep > n) {
    int p;
    if (set == (1 << (n - 1)))
      p = 0;
    else
      p = 1;
    ans = min(ans, tot + p);
    return;
  }
  int s0 = set & ((1 << (dep - 1)) - 1);
  for (int s = s0; s >= 0; s = (s - 1) & s0) {
    if (ck[dep][s]) {
      dfs(dep + 1, set ^ s, tot + c[dep] - d[s]);
    }
    if (s == 0) break;
  }
}
int main() {
  ready();
  dfs(1, all, 0);
  cout << ans << endl;
}
