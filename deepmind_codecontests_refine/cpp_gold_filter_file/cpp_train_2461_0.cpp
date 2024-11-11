#include <bits/stdc++.h>
const int factor_N = 10000005;
const int tree_arr_N = 1000005;
template <class T>
void chkmax(T& a, T b) {
  a > b ? (a = a) : (a = b);
}
template <class T>
void chkmin(T& a, T b) {
  a > b ? (a = b) : (a = a);
}
template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}
template <class T>
T max(T a, T b) {
  return a < b ? b : a;
}
template <class T>
inline bool rd(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return true;
}
template <class T>
inline void print(T x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
  return;
}
using std::cin;
using std::cout;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::vector;
int n;
const int N = 1e5 + 5;
char s[N];
int res, p = 1000000007, idx;
void solve(int num) {
  vector<vector<int>> f(n + 1, vector<int>(2, 0)), g(n + 1, vector<int>(2, 0));
  g[0][1] = num;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 1; ++j) {
      int temp = s[i] - '0';
      for (int k = 0; k <= 9; ++k) {
        if (j == 1 && k > temp) break;
        idx = (j == 1 && k == temp);
        if (k < num) {
          f[i][idx] = (f[i][idx] + f[i - 1][j]) % p;
          g[i][idx] = (g[i][idx] + g[i - 1][j]) % p;
        } else if (k == num) {
          f[i][idx] = (f[i][idx] + g[i - 1][j] + 10ll * f[i - 1][j]) % p;
          g[i][idx] = (g[i][idx] + g[i - 1][j]) % p;
        } else {
          f[i][idx] = (f[i][idx] + 10ll * f[i - 1][j]) % p;
          g[i][idx] = (g[i][idx] + 10ll * g[i - 1][j]) % p;
        }
      }
    }
  }
  res = (0ll + res + f[n][0] + f[n][1]) % p;
  return;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= 9; ++i) solve(i);
  print(res);
  puts("");
  return 0;
}
