#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void testCase() {
  ll n;
  cin >> n;
  for (int i = 1; i * i <= 2 * n; i++) {
    ll val = 2 * n - (i * (i + 1));
    ll dis = sqrt((val * 4) + 1);
    ll l = (-1 + dis) / 2;
    if ((i * (i + 1)) + (l * (l + 1)) == 2 * n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
  return;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  testCase();
  return 0;
}
