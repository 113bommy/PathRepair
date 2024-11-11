#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long> v, bv;
long long s, bans;
long long mpow, q, usd[2000000], ans[1200000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  mpow = 20;
  for (int i = n; i >= 0; --i) {
    q = i;
    while ((q ^ ((1 << mpow) - 1)) > n || usd[q ^ ((1 << mpow) - 1)] == 1) {
      --mpow;
    }
    usd[q ^ ((1 << mpow) - 1)] = 1;
    ans[i] = q ^ ((1 << mpow) - 1);
  }
  cout << n * (n + 1) << endl;
  for (int i = 0; i <= n; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  cin.get();
  cin.get();
  return 0;
}
