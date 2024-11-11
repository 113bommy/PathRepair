#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  ll s = 0;
  ll k = 1;
  while (s + k <= a + b) {
    s += k++;
  }
  --k;
  ll t = 0;
  ll l = 1;
  while (t <= a) {
    t += l++;
  }
  --l;
  ll skip = t - a;
  cout << l - 1 << '\n';
  for (int i = 1; i <= l; i++)
    if (i != skip) cout << i << " ";
  cout << '\n';
  if (skip > b) {
    cout << "0\n";
    return 0;
  }
  cout << k - (l - 1) << endl;
  cout << skip << " ";
  for (int i = l + 1; i <= k; ++i) cout << i << " ";
  cout << endl;
}
