#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, x, y;
    cin >> n >> x >> y;
    ll sum = x + y;
    if (x > y) swap(x, y);
    ll mx = min(n, x + y - 1);
    ll mn = max(1LL, (x + y - n + 1));
    cout << mn << " " << mx << endl;
  }
}
