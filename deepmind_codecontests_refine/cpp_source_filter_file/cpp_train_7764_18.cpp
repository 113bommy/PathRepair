#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using plll = pair<ll, pll>;
using pib = pair<int, bool>;
using pdi = pair<double, int>;
using pid = pair<int, double>;
using ld = long double;
using piiii = pair<pii, pii>;
ll n, x;
int q;
string second;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  int lg = log2(n + 1);
  for (int i = 0; i < q; i++) {
    cin >> x >> second;
    ll dep = 0;
    ll cur = 1;
    while (cur * 2 <= x) {
      cur *= 2;
      dep++;
    }
    while (cur != x) {
      dep--;
      if (cur > x)
        cur -= (ll)1 << dep;
      else
        cur += (ll)1 << dep;
    }
    for (int j = 0; j < second.length(); j++) {
      if (second[j] == 'U') {
        if (dep < lg - 1) {
          int par = (x - (ll)(1 << dep)) / ((ll)1 << (dep + 1)) % 2;
          if (!par)
            x += (ll)1 << dep;
          else
            x -= (ll)1 << dep;
          dep++;
        }
      } else if (second[j] == 'L') {
        if (dep > 0) {
          dep--;
          x -= (ll)1 << dep;
        }
      } else {
        if (dep > 0) {
          dep--;
          x += (ll)1 << dep;
        }
      }
    }
    cout << x << "\n";
  }
  return 0;
}
