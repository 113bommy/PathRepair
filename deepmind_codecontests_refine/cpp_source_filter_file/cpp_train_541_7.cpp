#include <bits/stdc++.h>
using namespace std;
const int mn = (1 << 17) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
int tt, ntest = 1;
void docfile() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (ifstream("test.inp")) {
    freopen("test.inp", "r", stdin);
    if (!aNs)
      freopen("test.out", "w", stdout);
    else
      freopen("test.ans", "w", stdout);
  } else if (ifstream("1315e.inp")) {
    freopen("1315e.inp", "r", stdin);
    freopen("1315e.out", "w", stdout);
  }
}
template <typename T>
void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-' ? -f : f, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename T>
void write(T a) {
  if (a < 0) {
    putchar('-');
    write(-a);
    return;
  }
  if (a < 10) {
    putchar('0' + a);
    return;
  }
  write(a / 10);
  putchar((char)('0' + (a % 10)));
}
bool ok[mn];
int f[17][mn][2][2];
void enter() {
  int n, k;
  cin >> n >> k;
  memset(f, -1, sizeof(f));
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    ok[--x] = 1;
  }
  for (int i = 0; i < (1 << n); ++i) f[0][i][ok[i]][0] = 0;
  int sol = 0;
  for (int t = 1; t <= n; ++t)
    for (int k = 0; k < (1 << (n - t)); ++k)
      for (int u1 = 0; u1 < 2; ++u1)
        for (int d1 = 0; d1 < 2; ++d1)
          for (int u2 = 0; u2 < 2; ++u2)
            for (int d2 = 0; d2 < 2; ++d2)
              for (int w1 = 0; w1 < 2; ++w1)
                for (int w2 = 0; w2 < 2; ++w2)
                  for (int w3 = 0; w3 < 2; ++w3)
                    if (f[t - 1][2 * k][u1][d1] != -1)
                      if (f[t - 1][2 * k + 1][u2][d2] != -1) {
                        int res = f[t - 1][2 * k][u1][d1] +
                                  f[t - 1][2 * k + 1][u2][d2];
                        if (d1 || d2) ++res;
                        int d31 = (w1 ? d2 : d1);
                        if (u1 || u2) ++res;
                        int d32 = (w2 ? u2 : u1);
                        int U = (w2 ? u1 : u2);
                        if ((d31 || d32) && (t != 1)) ++res;
                        int D = (w3 ? d31 : d32);
                        f[t][k][U][D] = max(f[t][k][U][D], res);
                        if (t == n) sol = max(sol, f[t][k][U][D] + (U || D));
                      }
  cout << sol;
}
void solve() {}
void print_result() {}
int main() {
  docfile();
  for (tt = 1; tt <= ntest; ++tt) {
    enter();
    solve();
    print_result();
  }
}
