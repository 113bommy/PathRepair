#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 2e18;
const int mod = 1e9 + 7;
const ld eps = 1e-9;
const ld pi = 3.14159265358979323846;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  int n;
  cin >> n;
  if (n & 1) {
    cout << 0;
    return 0;
  }
  cout << (int)pow(2, n / 2);
  return 0;
}
