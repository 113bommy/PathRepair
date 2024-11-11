#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 105;
const ll mod = 1e9 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector<ll> dil;
  if (n == 1) dil.push_back(1);
  for (int i = 2; i <= 1e6 && n != 1; i++) {
    while (n % i == 0) dil.push_back(i), n /= i;
  }
  if (n != 1) dil.push_back(n);
  if (dil.size() >= 3) {
    cout << 1 << E << dil[0] * dil[1];
  } else if (dil.size() == 1)
    cout << "1\n0";
  else
    cout << 2;
  return 0;
}
