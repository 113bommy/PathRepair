#include <bits/stdc++.h>
using namespace std;
int k, X, n, m;
string make(int x, int len, int a, int b) {
  string ans(len, 'X');
  int i = 0;
  if (a) ans[i++] = 'C';
  if (b) ans[len - 1] = 'A';
  while (x--) ans[i++] = 'A', ans[i++] = 'C';
  return ans;
}
int f1(int K, long long x, long long y, int a, int b, int c, int d) {
  if (K == 2) return y;
  return f1(K - 1, y, x + y + b * c, c, d, a, d);
}
void first(int x, int y, int a, int b, int c, int d) {
  if (2 * x + a + b > n) return;
  if (2 * y + c + d > m) return;
  if (f1(k, x, y, a, b, c, d) == X) {
    cout << make(x, n, a, b) << endl;
    cout << make(y, m, c, d) << endl;
    exit(0);
  }
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> k >> X >> n >> m;
  for (int i = 0; 2 * i <= n; ++i) {
    for (int j = 0; 2 * j <= m; ++j) {
      for (int k = 0; k < 16; ++k) {
        first(i, j, k & 1, 1 & (k >> 1), 1 & (k >> 2), 1 & (k >> 3));
      }
    }
  }
  cout << "Happy new year!\n";
  return 0;
}
