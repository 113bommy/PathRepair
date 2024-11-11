#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N = 1e9 + 7;
ll bpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll modinv(ll n, ll p) { return bpow(n, p - 2, p); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll a[n][5];
    ll ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    }
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    int temp1, temp2, win;
    for (int i = 0; i < 5; i++) {
      if (a[0][i] < a[1][i])
        temp1++;
      else
        temp2++;
    }
    if (temp1 > temp2)
      win = 0;
    else
      win = 1;
    for (int i = 2; i < n; i++) {
      temp1 = 0, temp2 = 0;
      for (int j = 0; j < 5; j++) {
        if (a[win][j] < a[i][j])
          temp1++;
        else
          temp2++;
      }
      if (temp2 > temp1) win = i;
    }
    for (int i = 0; i < n; i++) {
      if (i == win) continue;
      temp1 = 0, temp2 = 0;
      for (int j = 0; j < 5; j++) {
        if (a[win][j] < a[i][j])
          temp1++;
        else
          temp2++;
      }
      if (temp1 < temp2) {
        win = -2;
        break;
      }
    }
    cout << win + 1 << '\n';
  }
  return 0;
}
