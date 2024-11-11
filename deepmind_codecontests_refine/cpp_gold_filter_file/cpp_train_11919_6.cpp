#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
template <typename T>
inline void Cin(T& first) {
  char c;
  T sign = 1;
  first = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) first = first * 10 + c - '0';
  first *= sign;
}
template <typename T>
inline void Out(T first) {
  if (first > 9) Out(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void Cout(T first, char c) {
  if (first < 0) putchar('-');
  first = abs(first);
  Out(first);
  putchar(c);
}
template <typename T, typename... Args>
inline void Cin(T& a, Args&... args) {
  Cin(a);
  Cin(args...);
}
template <typename T, typename... Args>
inline void Cout(T a, char c, Args... args) {
  Cout(a, c);
  Cout(args...);
}
const int N = 1002;
const int T = 102;
int f[T][N], n, t, first, second;
vector<int> q[T];
void Enter() {
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    cin >> first >> second;
    q[t - first].emplace_back(second);
  }
  for (int i = 0; i <= t; ++i) sort(q[i].begin(), q[i].end(), greater<int>());
}
int DP(int high, int irene) {
  if (f[high][irene] != -1) return f[high][irene];
  int& res = f[high][irene];
  res = 0;
  if (high == t) return res;
  int s = 0;
  for (int i = 0; i <= irene; ++i) {
    res = max(res, DP(high + 1, min(2 * (irene - i), n)) + s);
    if (i < int(q[high].size())) s += q[high][i];
  }
  return res;
}
void Solve() {
  memset(&f, -1, sizeof f);
  cout << DP(0, 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("test"
            ".inp",
            "r")) {
    freopen(
        "test"
        ".inp",
        "r", stdin);
    freopen(
        "test"
        ".out",
        "w", stdout);
  }
  Enter(), Solve();
  return 0;
}
