#include <bits/stdc++.h>
const int N = 1000010;
const int mod = 1000000009;
int q, l, r, k;
int ans[10][N];
int f(int n) {
  int r = 1, d;
  while (n) {
    d = n % 10;
    if (d) r *= d;
    n /= 10;
  }
  return r;
}
int g(int n) { return n < 10 ? n : g(f(n)); }
void pre() {
  int temp;
  for (int i = (1); i < (N); ++i) {
    temp = g(i);
    for (int j = 0; j < (10); ++j) {
      ans[j][i] = ans[j][i - 1];
    }
    ++ans[temp][i];
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  pre();
  std::cin >> q;
  while (q--) {
    std::cin >> l;
    std::cin >> r;
    std::cin >> k;
    std::cout << ans[k][r] - ans[k][l - 1] << '\n';
  }
  return 0;
}
