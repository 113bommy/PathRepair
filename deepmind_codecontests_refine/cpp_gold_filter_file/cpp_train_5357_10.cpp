#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long int bigMod(long long int a, long long int b) {
  if (!b) return 1;
  long long int x = bigMod(a, b / 2);
  long long int temp = (x * x) % 1000000007;
  if (b % 2) temp = (temp * a) % 1000000007;
  return temp;
}
long long int modinv(long long int a) { return bigMod(a, 1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  int p, q, r, l;
  cin >> p >> q >> l >> r;
  int hash1[1002] = {0};
  int hash2[1002] = {0};
  int t1, t2;
  for (int i = 0; i < p; i++) {
    cin >> t1 >> t2;
    for (int j = t1; j <= t2; j++) hash1[j] = 1;
  }
  for (int i = 0; i < q; i++) {
    cin >> t1 >> t2;
    for (int j = t1; j <= t2; j++) hash2[j] = 1;
  }
  int cntr = 0;
  for (int i = l; i <= r; i++) {
    for (int j = 0; j <= (1000 - i); j++)
      if (hash1[j + i] && hash2[j]) {
        cntr++;
        break;
      }
  }
  cout << cntr;
  return 0;
}
