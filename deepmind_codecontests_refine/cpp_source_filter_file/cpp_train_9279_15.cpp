#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, x, y;
int main() {
  cin >> n >> x >> y;
  ll sum = 0;
  if (n > y) {
    cout << -1;
    return 0;
  }
  vector<ll> l;
  l.push_back(y + 1 - n);
  sum = (y + 1 - n) * (y + 1 - n);
  for (int i = 0; i < n - 1; i++) {
    l.push_back(1);
    sum += 1;
  }
  if (sum < x) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; i++) cout << l[i] << endl;
  return 0;
}
