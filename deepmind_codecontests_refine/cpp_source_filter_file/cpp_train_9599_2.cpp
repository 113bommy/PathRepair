#include <bits/stdc++.h>
using namespace std;
string s[2005], t[2005];
int a[2005], b[2005], n, F[10];
bool check() {
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++) {
    if (a[i]) b[a[i]]++;
  }
  int sum = 0;
  vector<int> v;
  for (int j = 2000; j >= 1; j--) {
    for (int k = 1; k <= b[j]; k++) {
      v.push_back(j);
    }
  }
  if (v.size() != n) return 0;
  int w = 0;
  int j = 0;
  for (j = 0; j < n - 1; j++) {
    w += v[j];
    if (w == j * (j + 1) / 2 + (j + 1) * (n - j - 1)) break;
  }
  if (j == n - 1)
    return 1;
  else
    return 0;
}
int main() {
  F[0] = F[1] = 1;
  for (int i = 1; i <= 10; i++) F[i] = F[i - 1] * i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (auto j : s[i]) {
      if (j == '1') {
        a[i]++;
      }
    }
  }
  if (n <= 6) {
    int ans = 10000, num;
    for (int i = 0; i < (1 << n); i++) {
      int x = __builtin_popcount(i);
      vector<int> g;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          g.push_back(j + 1);
          for (int k = 0; k < n; k++) {
            if (k != j) {
              if (s[j][k] == '0')
                s[j][k] = '1', s[k][j] = '0', a[j]++, a[k]--;
              else
                s[j][k] = '0', s[k][j] = '1', a[j]--, a[k]++;
            }
          }
        }
      }
      if (check()) {
        if (x < ans) {
          ans = x;
          num = 1;
        } else if (x == ans)
          num++;
      }
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          for (int k = 0; k < n; k++) {
            if (k != j) {
              if (s[j][k] == '0')
                s[j][k] = '1', s[k][j] = '0', a[j]++, a[k]--;
              else
                s[j][k] = '0', s[k][j] = '1', a[j]--, a[k]++;
            }
          }
        }
      }
    }
    if (ans > 10) {
      cout << -1;
      return 0;
    }
    cout << ans << ' ' << F[ans] * num;
    return 0;
  }
  if (check) {
    cout << 0 << ' ' << 1;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j != i) {
        if (s[i][j] == '0')
          a[i]++, a[j]--;
        else
          a[i]--, a[j]++;
      }
    }
    if (check()) ans++;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        if (s[i][j] == '0')
          a[i]--, a[j]++;
        else
          a[i]++, a[j]--;
      }
    }
  }
  cout << 1 << ' ' << ans;
}
