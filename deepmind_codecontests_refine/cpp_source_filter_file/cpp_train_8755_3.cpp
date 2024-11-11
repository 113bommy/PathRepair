#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
pair<int, int> e[100000];
int main() {
  ios::sync_with_stdio(0);
  long long n, a, b;
  cin >> n >> b >> a;
  b -= a;
  for (int i = 0; i < n; i++) {
    cin >> e[i].first >> e[i].second;
    e[i].second++;
  }
  sort(e, e + n);
  long long ans = 0;
  multiset<int> avail;
  for (int i = 0; i < n; i++) {
    int start = e[i].first, end = e[i].second;
    auto it = avail.lower_bound(start);
    if (it != avail.begin()) {
      --it;
      long long c1 = (end - *it) * a, c2 = (end - start) * a + b;
      ans = (ans + min(c1, c2)) % mod;
      avail.erase(it);
    } else {
      long long cost = (end - start) * a + b;
      ans = (ans + cost) % mod;
    }
    avail.insert(end);
  }
  cout << ans << endl;
}
