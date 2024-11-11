#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const int maxn = 2e5 + 5;
int n, a[maxn];
long long sum = 0;
multiset<long long> s;
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int c;
    long long ans = 0;
    cin >> c;
    s.insert(a[i] + sum);
    while (!s.empty() && *s.begin() <= sum + c) {
      ans += *s.begin() - sum;
      s.erase(s.begin());
    }
    ans += 1ll * c * (int)s.size();
    sum += c;
    cout << ans << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  int test_case = 1;
  while (test_case--) Solve();
  return 0;
}
