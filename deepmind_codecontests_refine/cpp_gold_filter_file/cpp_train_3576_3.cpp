#include <bits/stdc++.h>
using namespace std;
int dp[52][15][4][15][4][15][4];
map<int, int> mp;
int check(char *a, char *b, int *v, int n) {
  if (n == 0) return 1;
  if (n > 1) {
    if (dp[n][mp[a[n]]][mp[b[n]]][mp[a[n - 1]]][mp[b[n - 1]]][mp[a[n - 2]]]
          [mp[b[n - 2]]])
      return dp[n][mp[a[n]]][mp[b[n]]][mp[a[n - 1]]][mp[b[n - 1]]][mp[a[n - 2]]]
               [mp[b[n - 2]]];
  }
  int x;
  char y;
  int f = -1;
  if (v[n - 1] == 0 && (a[n] == a[n - 1] || b[n] == b[n - 1])) {
    x = a[n - 1];
    y = b[n - 1];
    a[n - 1] = a[n];
    b[n - 1] = b[n];
    if (check(a, b, v, n - 1) == 1) {
      f = 1;
    }
    a[n - 1] = x;
    b[n - 1] = y;
    if (n > 2)
      dp[n][mp[a[n]]][mp[b[n]]][mp[a[n - 1]]][mp[b[n - 1]]][mp[a[n - 2]]]
        [mp[b[n - 2]]] = f;
    if (f == 1) return f;
  }
  if (n < 3) return 0;
  if (v[n - 3] == 0 && (a[n] == a[n - 3] || b[n] == b[n - 3])) {
    x = a[n - 3];
    y = b[n - 3];
    a[n - 3] = a[n];
    b[n - 3] = b[n];
    if (check(a, b, v, n - 1) == 1) return 1;
    a[n - 3] = x;
    b[n - 3] = y;
    dp[n][mp[a[n]]][mp[b[n]]][mp[a[n - 1]]][mp[b[n - 1]]][mp[a[n - 2]]]
      [mp[b[n - 2]]] = f;
  }
  return f;
}
int main() {
  for (int i = 1; i <= 9; i++) mp[i + '0'] = i;
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 0;
  mp['S'] = 0;
  mp['D'] = 1;
  mp['H'] = 2;
  mp['C'] = 3;
  int n;
  cin >> n;
  char a[n];
  char b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans[n];
  memset(ans, 0, sizeof ans);
  if (check(a, b, ans, n - 1) == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
