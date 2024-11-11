#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 2e5 + 1;
const long long INF = 1e9;
void solve() {
  int n;
  cin >> n;
  int t = n;
  vector<int> pf, a(n);
  for (int i = 0; i < t; i++) cin >> a[i];
  for (int i = 2; i < n; i++) {
    if (n % i) continue;
    pf.push_back(i);
    while (n % i == 0) n /= i;
  }
  if (n != 1) pf.push_back(n);
  if (pf[0] == 2 and t % 4 == 0)
    pf[0] = 4;
  else if (pf[0] == 2)
    swap(pf[0], pf.back()), pf.pop_back();
  for (int p : pf) {
    for (int i = 0; i < t / p; i++) {
      int cnt = 0;
      for (int j = i; cnt < p and a[j]; j = (j + t / p) % t, cnt++)
        ;
      if (cnt == p) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T = 1;
  while (T--) solve();
}
