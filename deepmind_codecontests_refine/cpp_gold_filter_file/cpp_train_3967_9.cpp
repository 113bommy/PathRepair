#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1e9 + 7;
const long long INF = 1e14;
long long mpow(long long a, long long b, long long p = MOD) {
  a = a % p;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b = b >> 1;
  }
  return res % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < (int)(2000); ++i) cout << "5";
  cout << "\n";
  for (int i = 0; i < (int)(1999); ++i) cout << "4";
  cout << "5";
  return 0;
}
