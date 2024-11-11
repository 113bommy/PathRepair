#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int INF = 1000000009;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n;
  int m, k;
  long long x, s;
  cin >> n >> m >> k;
  cin >> x >> s;
  long long a[MAXN];
  long long b[MAXN];
  vector<pair<long long, long long> > sc(k);
  long long d[MAXN];
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < m; ++j) {
    cin >> b[j];
  }
  for (int i = 0; i < k; ++i) {
    cin >> sc[i].second;
  }
  for (int j = 0; j < k; ++j) {
    cin >> sc[j].first;
  }
  sort(sc.begin(), sc.end());
  long long curC = 0;
  for (auto item : sc) {
    if (item.first <= s && item.second > curC) {
      curC = item.second;
    }
  }
  long long tAns = (n - curC) * x;
  long long ans = n * x;
  long long cur1 = -1, cur2 = -1;
  for (int i = 0; i < m; ++i) {
    long long ks = s - b[i];
    if (ks < 0) {
      continue;
    }
    long long curC = 0;
    auto it = std::upper_bound(sc.begin(), sc.end(), make_pair(ks, 0 * 1LL));
    if (it != sc.begin()) {
      --it;
      curC = it == sc.end() || it->first > ks ? 0 : it->second;
      cur2 = it == sc.end() ? -1 : distance(sc.begin(), it);
    }
    long long cAns = (n - curC) * a[i];
    if (ans > cAns) {
      ans = cAns;
      cur1 = i;
    }
  }
  if (ans > tAns) {
    ans = tAns;
  }
  cout << ans;
  return 0;
}
