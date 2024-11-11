#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acosl(-1);
const int mod = 998244353;
const int mod1 = 1e9 + 7;
mt19937_64 rnd(time(0));
void faster() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}
void solve() {
  long long n;
  cin >> n;
  long long now = n + 1;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort((a).rbegin(), (a).rend());
  for (int i = 0; i < n; i++) {
    if (a[i] > now) {
      now--;
    }
  }
  cout << now + 1 << '\n';
}
signed main() {
  faster();
  double start = clock();
  long long t;
  cin >> t;
  while (t--) solve();
  cerr << "Time " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s\n";
  return 0;
}
