#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
int f[100005];
void add_edge(int s, int t, int w) {
  if (s > t) swap(s, t);
  while (s <= t) f[s++] += w;
}
void solve_five(int n) {
  printf("%d %d %d\n", n - 1, n, 1);
  add_edge(n - 1, n, 1);
  printf("%d %d %d\n", n - 3, n - 1, 2);
  add_edge(n - 3, n - 1, 2);
  printf("%d %d %d\n", n - 4, n - 3, 3);
  add_edge(n - 4, n - 3, 3);
  printf("%d %d %d\n", n - 4, n - 2, 1);
  add_edge(n - 4, n - 2, 1);
  vector<int> ans;
  ans.push_back(n - 2), ans.push_back(n - 1), ans.push_back(n - 2),
      ans.push_back(n);
  for (int i = 0; i < ans.size(); i += 2) printf("%d %d\n", ans[i], ans[i + 1]);
}
void solve(int n) {
  int half = n >> 1;
  for (int i = 1; i <= half; ++i) printf("%d %d %d\n", i, i + half, 1);
  for (int j = half, k = 1; j + 1 <= n; ++j, k += 2)
    printf("%d %d %d\n", j, j + 1, k);
  for (int i = 1; i < half; ++i) printf("%d %d\n", i, i + 1);
  puts("1 3");
}
int main() {
  int n = Rint();
  if (n == 5)
    solve_five(5);
  else
    solve(n);
  return 0;
}
