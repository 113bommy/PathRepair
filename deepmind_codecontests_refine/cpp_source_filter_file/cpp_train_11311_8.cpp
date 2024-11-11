#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const long long INF = 1e12 + 1;
const int N = 10e5 + 2;
unsigned long long n, m;
int main() {
  cin >> n >> m;
  while (m * 2 <= n || n * 2 <= m) {
    if (n * 2 <= m) m %= n * 2;
    if (n == 0 || m == 0) {
      cout << n << ' ' << m;
      exit(0);
    }
    if (m * 2 <= n) n %= m * 2;
    if (n == 0 || m == 0) {
      cout << n << ' ' << m;
      exit(0);
    }
  }
  cout << n << ' ' << main;
  exit(0);
}
