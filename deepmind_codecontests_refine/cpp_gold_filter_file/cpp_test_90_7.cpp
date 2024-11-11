#include <bits/stdc++.h>
using namespace std;
long long mod = (1 ? 1e9 + 7 : 998244353);
const int N = 1e5 + 5;
const int M = 20 * N;
void Evlos() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << '\n';
  } else if (x > y) {
    cout << x + y << '\n';
  } else {
    long long k = y / x;
    k -= 2;
    k = (k + 1) / 2;
    cout << (x + y) / 2 + k * x << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) Evlos();
  return 0;
}
