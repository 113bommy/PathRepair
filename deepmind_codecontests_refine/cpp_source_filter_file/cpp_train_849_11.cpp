#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using namespace std::chrono;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll inf = 1100000000;
  int n;
  cin >> n;
  int pro = 1;
  ll pos = 1;
  ll neg = 0;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    if (temp < 0) pro *= -1;
    if (pro < 0)
      neg++;
    else
      pos++;
  }
  ll x = neg * pos;
  ll val = (n * (n + 1));
  cout << x << ' ' << val / 2 - (x) << endl;
  return 0;
}
