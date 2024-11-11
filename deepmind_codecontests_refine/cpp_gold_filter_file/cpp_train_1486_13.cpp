#include <bits/stdc++.h>
using namespace std;
constexpr int kN = int(1E6 + 10);
string s[kN], ns[kN];
int val[kN], tmp[kN], v2[kN][2], t2[kN][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, r, a, b, c, d;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  if (n > m) {
    swap(n, m);
    for (int i = 0; i < n; i++) ns[i] = s[i];
    for (int i = 0; i < m; i++) s[i].resize(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) s[j][i] = ns[i][j];
  }
  if (n >= 4)
    cout << -1 << '\n';
  else if (n == 3) {
    for (int i = 1; i < m; i++) {
      v2[i][0] = (s[0][i] - '0' + s[0][i - 1] - '0' + s[1][i] - '0' +
                  s[1][i - 1] - '0') &
                 1;
      v2[i][1] = (s[2][i] - '0' + s[2][i - 1] - '0' + s[1][i] - '0' +
                  s[1][i - 1] - '0') &
                 1;
    }
    a = 0, b = 1, c = 1, d = 1;
    for (int i = 1; i < m; i++) {
      t2[i][0] = v2[i][0];
      t2[i][1] = v2[i][1];
    }
    for (int i = 1; i < m; i++)
      if (t2[i][0] != 1 || t2[i][1] != 1) {
        t2[i + 1][0] ^= t2[i][0] ^ 1;
        t2[i + 1][1] ^= t2[i][1] ^ 1;
        a++;
      }
    for (int i = 1; i < m; i++) {
      t2[i][0] = v2[i][0];
      t2[i][1] = v2[i][1];
    }
    t2[1][0] ^= 1;
    for (int i = 1; i < m; i++)
      if (t2[i][0] != 1 || t2[i][1] != 1) {
        t2[i + 1][0] ^= t2[i][0] ^ 1;
        t2[i + 1][1] ^= t2[i][1] ^ 1;
        b++;
      }
    for (int i = 1; i < m; i++) {
      t2[i][0] = v2[i][0];
      t2[i][1] = v2[i][1];
    }
    t2[1][1] ^= 1;
    for (int i = 1; i < m; i++)
      if (t2[i][0] != 1 || t2[i][1] != 1) {
        t2[i + 1][0] ^= t2[i][0] ^ 1;
        t2[i + 1][1] ^= t2[i][1] ^ 1;
        c++;
      }
    for (int i = 1; i < m; i++) {
      t2[i][0] = v2[i][0];
      t2[i][1] = v2[i][1];
    }
    t2[1][0] ^= 1;
    t2[1][1] ^= 1;
    for (int i = 1; i < m; i++)
      if (t2[i][0] != 1 || t2[i][1] != 1) {
        t2[i + 1][0] ^= t2[i][0] ^ 1;
        t2[i + 1][1] ^= t2[i][1] ^ 1;
        d++;
      }
    cout << min({a, b, c, d}) << '\n';
  } else if (n == 2) {
    for (int i = 1; i < m; i++)
      val[i] = (s[0][i] - '0' + s[0][i - 1] - '0' + s[1][i] - '0' +
                s[1][i - 1] - '0') &
               1;
    for (int i = 1; i < m; i++) tmp[i] = val[i];
    l = 0, r = 1;
    for (int i = 1; i < m; i++)
      if (tmp[i] == 0) {
        tmp[i] ^= 1;
        tmp[i + 1] ^= 1;
        l++;
      }
    for (int i = 1; i < m; i++) tmp[i] = val[i];
    tmp[1] ^= 1;
    for (int i = 1; i < m; i++)
      if (tmp[i] == 0) {
        tmp[i] ^= 1;
        tmp[i + 1] ^= 1;
        r++;
      }
    cout << min(l, r) << '\n';
  } else
    cout << 0 << '\n';
}
