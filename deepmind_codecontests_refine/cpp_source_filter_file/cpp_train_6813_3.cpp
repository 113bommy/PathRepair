#include <bits/stdc++.h>
using namespace std;
const int N = 2000000;
long long n, m, k, p, s1[N], s2[N], ans = -1e18, x, y;
long long ans1[N], ans2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      s1[i] += x;
      s2[j] += x;
    }
  }
  multiset<long long> t1, t2;
  for (int i = 1; i <= n; i++) {
    t1.insert(-s1[i]);
  }
  for (int i = 1; i <= m; i++) {
    t2.insert(-s2[i]);
  }
  for (int i = 1; i <= k; i++) {
    auto k1 = (*t1.begin());
    auto k2 = (*t2.begin());
    ans1[i] = ans1[i - 1] - k1;
    t1.erase(t1.begin());
    t1.insert(k1 + m * p);
    ans2[i] = ans2[i] - k2;
    t2.erase(t2.begin());
    t2.insert(k2 + n * p);
  }
  for (long long i = 0; i <= k; i++) {
    ans = max(ans, ans1[i] + ans2[k - i] - i * (k - i) * p);
  }
  cout << ans;
}
