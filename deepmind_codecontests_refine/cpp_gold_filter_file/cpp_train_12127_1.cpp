#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
char b[N];
int f[N] = {-1};
bool vis[N] = {false};
bool vis1[N] = {false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t, a;
  string s;
  cin >> n >> t;
  cin >> s;
  int tt = t;
  while (t--) {
    cin >> a;
    vis[a - 1] = true;
  }
  int m = s.size();
  for (int i = 1; i < m; i++) {
    int j = f[i - 1];
    while (s[j + 1] != s[i] && j >= 0) j = f[j];
    if (s[j + 1] == s[i])
      f[i] = j + 1;
    else
      f[i] = -1;
  }
  int i = 0, j = 0, cnt = 0;
  t = -1;
  while (i < n) {
    if (vis[i]) t = i;
    if (t != -1) {
      if (i - t < m) {
        vis1[i] = true;
        if (s[i - t] == s[j]) {
          i++;
          j++;
          if (j == m) {
            cnt++;
            j = f[j - 1] + 1;
          }
        } else {
          if (j == 0)
            i++;
          else
            j = f[j - 1] + 1;
        }
      } else
        i++;
    } else
      i++;
  }
  if (cnt < tt) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < n; i++)
    if (!vis1[i]) ans = (ans * 26) % MOD;
  cout << ans << endl;
  return 0;
}
