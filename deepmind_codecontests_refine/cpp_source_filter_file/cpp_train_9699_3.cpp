#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const double PI = acos(-1.0);
const int MAX_N = 1005;
int n, m;
char A[MAX_N][MAX_N];
int cnt1[MAX_N][MAX_N], cnt2[MAX_N][MAX_N];
int suf[MAX_N][MAX_N], pref[MAX_N][MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cnt2[i][m - 1] = 1;
    for (int j = m - 2; j >= 0; j--) {
      if (A[i][j] == A[i][j + 1]) {
        cnt2[i][j] = cnt2[i][j + 1] + 1;
      } else {
        cnt2[i][j] = 1;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    cnt1[n - 1][j] = 1;
    suf[n - 1][j] = cnt2[n - 1][j];
    for (int i = n - 2; i >= 0; i--) {
      if (A[i][j] == A[i + 1][j]) {
        cnt1[i][j] = cnt1[i + 1][j] + 1;
        suf[i][j] = min(suf[i + 1][j], cnt2[i][j]);
      } else {
        cnt1[i][j] = 1;
        suf[i][j] = cnt2[i][j];
      }
    }
    pref[0][j] = cnt2[0][j];
    for (int i = 1; i < n; i++) {
      if (A[i][j] == A[i - 1][j]) {
        pref[i][j] = min(pref[i - 1][j], cnt2[i][j]);
      } else {
        pref[i][j] = cnt2[i][j];
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int i1 = i;
      int i2 = i1 + cnt1[i1][j];
      if (i2 == n) continue;
      int i3 = i2 + cnt1[i2][j];
      if (i3 == n) continue;
      if (cnt1[i1][j] != cnt1[i2][j]) continue;
      if (cnt1[i3][j] < cnt1[i1][j]) continue;
      int m1 = suf[i1][j];
      int m2 = suf[i2][j];
      int m3 = pref[i3 + cnt1[i3][j] - 1][j];
      res += min(m1, min(m2, m3));
    }
  }
  cout << res;
  return 0;
}
