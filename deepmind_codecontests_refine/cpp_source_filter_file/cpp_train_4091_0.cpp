#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 10, OO = 1e9 + 10;
const long double pi = acos(-1);
long long w, n, ans, t;
pair<long long, long long> a[MAX];
vector<long long> v;
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first > p2.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    ans = 0;
    v.clear();
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
    sort(a, a + n);
    int i;
    for (i = 0; i < n; i++) {
      if (ans + a[i].first <= w) {
        v.push_back(a[i].second);
        ans += a[i].first;
      }
    }
    if (ans >= (w + 1) / 2) {
      cout << v.size() << "\n";
      for (auto it : v) cout << it << " ";
      cout << '\n';
    } else
      cout << -1 << '\n';
  }
  return 0;
}
