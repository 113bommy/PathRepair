#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long double EPS = 1e-9;
const int MOD = 1000000007;
const long long LLINF = 1000000000000000001;
const int maxn = 100042;
int n, m;
pair<pair<int, int>, int> p[maxn];
pair<pair<int, int>, int> a[maxn];
int k[maxn];
int ans[maxn];
struct cmp2 {
  bool operator()(const pair<pair<int, int>, int> &a,
                  const pair<pair<int, int>, int> &b) const {
    return a.first.second < b.first.second;
  }
};
set<pair<pair<int, int>, int>, cmp2> active;
void NO() {
  cout << "NO\n";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first.first >> p[i].first.second;
    p[i].second = i;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first.first >> a[i].first.second >> k[i];
    a[i].second = i;
  }
  sort(p + 1, p + 1 + n);
  sort(a + 1, a + 1 + m);
  int i = 1;
  int j = 1;
  while (i <= n || j <= m) {
    while (j <= m && (i == n + 1 || a[j].first.first <= p[i].first.first)) {
      active.insert(a[j]);
      j++;
    }
    while (i <= n && (j == m + 1 || p[i].first.first <= a[j].first.first)) {
      if (active.empty()) {
        NO();
      }
      auto iter = active.lower_bound(p[i]);
      if (iter == active.end()) {
        NO();
      }
      int index = iter->second;
      k[index]--;
      if (k[index] == 0) active.erase(iter);
      ans[p[i].second] = index;
      i++;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
}
