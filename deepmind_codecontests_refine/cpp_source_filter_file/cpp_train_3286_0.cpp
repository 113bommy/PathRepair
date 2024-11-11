#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
ll n;
bool isPrime(ll x) {
  if (x <= 1) return 0;
  if (x <= 3) return 1;
  if (x % 2 == 0 || x % 3 == 0) return 0;
  for (ll i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || n % (i + 2) == 0) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (isPrime(n)) {
    cout << 1 << "\n";
    ;
  } else if ((n & 1) == 0 || isPrime(n - 2)) {
    cout << 2 << "\n";
    ;
  } else {
    cout << 3 << "\n";
    ;
  }
  return 0;
}
