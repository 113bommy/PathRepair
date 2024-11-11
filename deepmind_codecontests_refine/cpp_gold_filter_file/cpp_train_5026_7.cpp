#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long int MOD1 = 1e9 + 7;
const long long int MAX5 = 1e5;
const long long int MAX6 = 1e6;
const long long int MAX7 = 1e7;
const long long int MAX8 = 1e8;
const long long int MAX9 = 1e9;
const long long int MAX10 = 1e10;
const long long int MAXX = 1e18;
long long int po(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
long long int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(a % b, b);
}
int t = 0;
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a + b) % 2 && a + d > 0)
    cout << "Ya ";
  else
    cout << "Tidak ";
  if ((a + b) % 2 && b + c > 0)
    cout << "Ya ";
  else
    cout << "Tidak ";
  if ((a + b) % 2 == 0 && b + c > 0)
    cout << "Ya ";
  else
    cout << "Tidak ";
  if ((a + b) % 2 == 0 && a + d > 0)
    cout << "Ya ";
  else
    cout << "Tidak ";
}
int main() {
  int tttt;
  cin >> tttt;
  for (int TTTT = 1; TTTT <= tttt; TTTT++) {
    t++;
    solve();
    cout << "\n";
    ;
  }
}
