#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int k, b, n, t;
  cin >> k >> b >> n >> t;
  int a = k + b;
  while (1) {
    if (t < a) break;
    a = a * k + b;
    n--;
  }
  cout << max(n, 0);
}
