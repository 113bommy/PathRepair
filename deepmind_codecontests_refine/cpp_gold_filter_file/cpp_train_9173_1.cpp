#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const lli md = 998244353;
lli fact[1000001];
lli solve(lli n) {
  if (n <= 2) return 0;
  return n * (fact[n - 1] + solve(n - 1) - 1) % md;
}
int main() {
  fast();
  fact[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    fact[i] = ((i % md) * (fact[i - 1] % md)) % md;
  lli q;
  q = 1;
  while (q--) {
    lli n;
    cin >> n;
    cout << 1ll * (fact[n] % md + solve(n) % md) % md << "\n";
  }
}
