#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long happy[100010];
void solve() {
  long long n, m;
  cin >> n >> m;
  long long b;
  cin >> b;
  for (long long i = 0; i < b; i++) {
    long long a;
    cin >> a;
    happy[a] = 1;
  }
  long long d;
  cin >> d;
  for (long long i = 0; i < d; i++) {
    long long b;
    cin >> b;
    happy[b] = 1;
  }
  for (long long i = 0; i <= n * m; i++) {
    long long tp = happy[i % n];
    tp = tp | happy[i % m];
    happy[i % n] = tp;
    happy[i % m] = tp;
  }
  for (long long i = 0; i < max(n, m); i++)
    if (!happy[i]) {
      cout << "No";
      return;
    }
  cout << "Yes";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) solve();
  return 0;
}
