#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int N = 5e5 + 7;
const int MOD = 1e9 + 7;
constexpr int mul(int a, int b) { return 1LL * a * b % MOD; }
template <typename... T>
constexpr int mul(int a, int b, T... t) {
  return mul(mul(a, b), t...);
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long int readl() {
  char ch = getchar();
  long long int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int A[N], ans[1010][1010];
int main() {
  int q = read();
  int MAX = 0;
  for (int i = 1; i <= q; i++) {
    int op = read(), x = read(), y = read();
    if (op == 1) {
      A[x] += y;
      for (int i = 1; i < 1010; i++) {
        ans[i][x % i] += y;
      }
    } else {
      long long int res = 0;
      if (x >= 1010) {
        for (int i = y; i < N; i += x) {
          res += A[i];
        }
      } else {
        res = ans[x][y];
      }
      cout << res << endl;
    }
  }
  return 0;
}
