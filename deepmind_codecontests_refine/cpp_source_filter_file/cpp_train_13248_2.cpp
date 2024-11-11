#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
int t;
int main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << n << endl;
    else
      cout << n - 1 << endl;
  }
}
