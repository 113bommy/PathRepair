#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int dp[200][200][200];
int m[3], c[3];
void solve(int a, int b, int c) {
  if (a + b + c == 1) {
    if (a) m[0] = 1;
    if (b) m[1] = 1;
    if (c) m[2] = 1;
    return;
  }
  if (dp[a][b][c]) return;
  dp[a][b][c] = 1;
  if (a > 1) solve(a - 1, b, c);
  if (b > 1) solve(a, b - 1, c);
  if (c > 1) solve(a, b, c - 1);
  if (a and b) solve(a - 1, b - 1, c + 1);
  if (b and c) solve(a + 1, b - 1, c - 1);
  if (c and a) solve(a - 1, b + 1, c - 1);
}
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'R') c[0]++;
    if (a[i] == 'G') c[1]++;
    if (a[i] == 'B') c[2]++;
  }
  solve(c[0], c[1], c[2]);
  if (m[2]) putchar('B');
  if (m[1]) putchar('G');
  if (m[0]) putchar('R');
  cout << endl;
  return 0;
}
