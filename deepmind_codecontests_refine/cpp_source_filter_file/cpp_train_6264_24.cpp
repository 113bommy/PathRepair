#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ll n;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; i++) cin >> a[i];
  ll pos = *max_element(a, a + n);
  bool flag = 1;
  for (ll i = 0; i < pos; i++)
    if (a[i] > a[i + 1]) {
      flag = 0;
      break;
    }
  for (ll i = pos; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
