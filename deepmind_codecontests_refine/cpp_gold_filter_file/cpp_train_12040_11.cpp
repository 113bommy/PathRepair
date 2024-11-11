#include <bits/stdc++.h>
using namespace std;
int q, l, r, k;
int acum[1000010][10];
int f(int x) {
  int ans = 1;
  while (x) {
    ans *= (x % 10 != 0) ? x % 10 : 1;
    x /= 10;
  }
  return ans;
}
int g(int x) {
  if (x < 10) return x;
  return g(f(x));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  int calc;
  for (int i = 1; i < 1000001; ++i) {
    calc = g(i);
    for (int j = 1; j < 10; ++j) {
      acum[i][j] = acum[i - 1][j];
    }
    acum[i][calc]++;
  }
  while (q) {
    cin >> l >> r >> k;
    cout << acum[r][k] - acum[l - 1][k] << '\n';
    q--;
  }
  return 0;
}
