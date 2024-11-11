#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    ll v;
    cin >> v;
    s += v;
  }
  cout << s / n << endl;
  return 0;
}
