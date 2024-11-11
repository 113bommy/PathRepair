#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  t = 1;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a >= c)
      cout << "-1 ";
    else
      cout << "1 ";
    if (c >= a * b)
      cout << "-1 ";
    else
      cout << b << " ";
    cout << "\n";
  }
}
