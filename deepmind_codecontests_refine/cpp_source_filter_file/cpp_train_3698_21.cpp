#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
long long gcd(long long u, long long v);
void boost_io();
bool isPrime(long long x);
int main() {
  boost_io();
  int n;
  cin >> n;
  int r = 0, g = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    char next;
    cin >> next;
    switch (next) {
      case 'R':
        r++;
        break;
      case 'G':
        g++;
        break;
      case 'B':
        b++;
        break;
    }
  }
  if ((r > 0 && g > 0 && b > 0) || (r > 1 && b > 1) || (r > 1 && g > 1) ||
      (b > 1 && g > 1))
    cout << "RGB" << endl;
  else if ((r != 0 && g == 0 && b == 0) || (r == 0 && g == 1 && b == 1))
    cout << 'R' << endl;
  else if ((r == 0 && g != 0 && b == 0) || (r == 1 && g == 0 && b == 1))
    cout << 'G' << endl;
  else if ((r == 0 && g == 0 && b != 0) || (r == 1 && g == 1 && b == 0))
    cout << 'B' << endl;
  else if (r > 1 && g + b == 1)
    cout << "GB" << endl;
  else if (b > 1 && r + g == 1)
    cout << "RG" << endl;
  else if (g > 1 && r + b == 1)
    cout << "RB" << endl;
  return 0;
}
inline void boost_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
inline long long gcd(long long u, long long v) {
  while (v != 0) {
    long long r = u % v;
    u = v;
    v = r;
  }
  return u;
}
bool isPrime(long long x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (long long i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
