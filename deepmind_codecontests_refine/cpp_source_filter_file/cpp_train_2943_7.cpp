#include <bits/stdc++.h>
using namespace std;
long long n, m;
char a[2020][2020];
int up[2020][2020];
int dw[2020][2020];
int le[2020][2020];
int ri[2020][2020];
int leup[2020][2020];
int ledw[2020][2020];
int riup[2020][2020];
int ridw[2020][2020];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int i1 = 1; i1 <= m; i1++) {
      cin >> a[i][i1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int i1 = 1; i1 <= m; i1++) {
      if (a[i][i1] == a[i - 1][i1]) {
        up[i][i1] = up[i - 1][i1] + 1;
      } else {
        up[i][i1] = 1;
      }
      if (a[i][i1] == a[i][i1]) {
        le[i][i1] = le[i][i1 - 1] + 1;
      } else {
        le[i][i1] = 1;
      }
      if (a[i][i1] == a[i - 1][i1 - 1]) {
        leup[i][i1] = min(leup[i - 1][i1 - 1] + 2, min(up[i][i1], le[i][i1]));
      } else {
        leup[i][i1] = min(2, min(up[i][i1], le[i][i1]));
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int i1 = m; i1 >= 1; i1--) {
      if (a[i][i1] == a[i][i1 + 1]) {
        ri[i][i1] = ri[i][i1 + 1] + 1;
      } else {
        ri[i][i1] = 1;
      }
      if (a[i][i1] == a[i + 1][i1]) {
        dw[i][i1] = dw[i + 1][i1] + 1;
      } else {
        dw[i][i1] = 1;
      }
      if (a[i][i1] == a[i + 1][i1 + 1]) {
        ridw[i][i1] = min(ridw[i + 1][i1 + 1] + 2, min(ri[i][i1], dw[i][i1]));
      } else {
        ridw[i][i1] = min(2, min(ri[i][i1], dw[i][i1]));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int i1 = m; i1 >= 1; i1--) {
      if (a[i][i1] == a[i - 1][i1 + 1]) {
        riup[i][i1] = min(riup[i - 1][i1 + 1] + 2, min(ri[i][i1], up[i][i1]));
      } else {
        riup[i][i1] = min(2, min(ri[i][i1], up[i][i1]));
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int i1 = 1; i1 <= m; i1++) {
      if (a[i][i1] == a[i + 1][i1 - 1]) {
        ledw[i][i1] = min(ledw[i + 1][i1 - 1] + 2, min(le[i][i1], dw[i][i1]));
      } else {
        ledw[i][i1] = min(2, min(le[i][i1], dw[i][i1]));
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int i1 = 1; i1 <= m; i1++) {
      ans += min(min(leup[i][i1], riup[i][i1]), min(ledw[i][i1], ridw[i][i1]));
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  q = 1;
  while (q != 0) {
    solve();
    --q;
  }
}
