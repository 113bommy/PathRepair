#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (auto &a : p) cin >> a;
  vector<string> mat(n);
  for (auto &a : mat) cin >> a;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
      for (ll k = 0; k < n; k++)
        if (mat[i][j] == '1' && mat[j][k] == '1') mat[i][k] = '1';
  for (ll i = 0; i < n; i++) {
    ll ch = i;
    for (ll j = i + 1; j < n; j++)
      if (mat[i][j] == '1') {
        if (p[ch] > p[j]) ch = j;
      }
    swap(p[ch], p[i]);
  }
  for (ll i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
}
