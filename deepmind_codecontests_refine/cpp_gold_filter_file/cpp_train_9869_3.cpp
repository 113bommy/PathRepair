#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ll a, b;
  cin >> a >> b;
  ll d = gcd(a, b);
  ll r = 1;
  ll t = d;
  for (ll i = 2; i <= t && i * i <= d; i++) {
    if (t % i == 0) {
      r++;
      while (t % i == 0) t /= i;
    }
  }
  r += t > 1;
  cout << r << endl;
}
