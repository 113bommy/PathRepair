#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  ll r = 0;
  for (ll i = 1; i <= n; i++) r += i * (n + 1 - i);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    r -= (u + 1) * (n - v);
  }
  cout << r << endl;
}
