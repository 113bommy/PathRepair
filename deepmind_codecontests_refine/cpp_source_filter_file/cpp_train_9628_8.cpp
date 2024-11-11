#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
int n, k, ok;
char b[111][111];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  if (k * 2 <= (n * n + 1) / 2) return cout << "NO\n", 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) b[i][j] = 'S';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (k) {
        if (!(i & 1)) {
          if (!(j & 1)) b[i][j] = 'L', k--;
        } else if (j & 1)
          b[i][j] = 'L', k--;
      }
      if (!k) ok = 1;
    }
    if (ok) break;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << b[i] << endl;
  return 0;
}
