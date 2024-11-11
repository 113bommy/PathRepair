#include <bits/stdc++.h>
using ll = long long;
constexpr ll MOD = (ll)(1e8);
using namespace std;
ll a, m;
int main() {
  bool ok = false;
  cin >> a >> m;
  for (int i = 1; i <= 1e5; i++) {
    if (a % m == 0) ok = true;
    a += (a % m);
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
