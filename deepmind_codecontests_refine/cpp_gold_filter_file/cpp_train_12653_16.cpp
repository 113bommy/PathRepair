#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
bool debug = false;
map<long long int, set<long long int>> mp1;
map<long long int, set<long long int>> mp2;
long long int power[61] = {0};
long long int N;
vector<pair<long long int, pair<long long int, long long int>>> segtree1;
vector<pair<long long int, pair<long long int, long long int>>> segtree2;
void fill1(long long int v) {
  if (2 * v + 1 < power[N + 1] - 1) {
    fill1(2 * v + 1);
    fill1(2 * v + 2);
    segtree1[v].first =
        max(segtree1[2 * v + 1].first, segtree1[2 * v + 2].first);
    segtree1[v].second.first = segtree1[2 * v + 1].second.first;
    segtree1[v].second.second = segtree1[2 * v + 2].second.second;
  } else {
    return;
  }
}
long long int mx(long long int l, long long int r, long long int v) {
  if (segtree1[v].second.first >= l && segtree1[v].second.second <= r) {
    return segtree1[v].first;
  } else if (segtree1[v].second.second < l || segtree1[v].second.first > r) {
    return -inf;
  } else {
    return max(mx(l, r, 2 * v + 1), mx(l, r, 2 * v + 2));
  }
}
void fill2(long long int v) {
  if (2 * v + 1 < power[N + 1] - 1) {
    fill2(2 * v + 1);
    fill2(2 * v + 2);
    segtree2[v].first =
        min(segtree2[2 * v + 1].first, segtree2[2 * v + 2].first);
    segtree2[v].second.first = segtree2[2 * v + 1].second.first;
    segtree2[v].second.second = segtree2[2 * v + 2].second.second;
  } else {
    return;
  }
}
long long int mn(long long int l, long long int r, long long int v) {
  if (segtree2[v].second.first >= l && segtree2[v].second.second <= r) {
    return segtree2[v].first;
  } else if (segtree2[v].second.second < l || segtree2[v].second.first > r) {
    return inf;
  } else {
    return min(mn(l, r, 2 * v + 1), mn(l, r, 2 * v + 2));
  }
}
long long int bin1(long long int j, long long int x);
long long int bin2(long long int j, long long int x);
long long int find1(long long int j, long long int m);
long long int find2(long long int j, long long int m);
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n), b(n);
  for (long long int j = 0; j < n; j++) {
    cin >> a[j];
    mp1[a[j]].insert(j);
  }
  for (long long int j = 0; j < n; j++) {
    cin >> b[j];
    mp2[b[j]].insert(j);
  }
  for (long long int j = 0; j <= 60; j++) {
    if (power[j] >= n) {
      N = j;
      break;
    }
  }
  segtree1.resize(power[N + 1] - 1);
  segtree2.resize(power[N + 1] - 1);
  for (long long int j = n; j < power[N]; j++) {
    a.push_back(-inf);
    b.push_back(inf);
  }
  for (long long int j = power[N] - 1; j < power[N + 1] - 1; j++) {
    segtree1[j].first = a[j - (power[N] - 1)];
    segtree1[j].second.first = j - power[N] + 1;
    segtree1[j].second.second = j - power[N] + 1;
    segtree2[j].first = b[j - (power[N] - 1)];
    segtree2[j].second.first = j - power[N] + 1;
    segtree2[j].second.second = j - power[N] + 1;
  }
  fill1(0);
  fill2(0);
  vector<pair<long long int, long long int>> dp(n);
  if (a[0] == b[0]) {
    dp[0] = {a[0], 1};
  } else {
    dp[0] = {-inf, 0};
  }
  for (long long int j = 1; j < n; j++) {
    if (a[j] == b[j]) {
      long long int i1 = bin1(j, a[j]);
      long long int i2 = bin2(j, b[j]);
      dp[j] = {a[j], min(j - i1 + 1, j - i2 + 1)};
    } else if (a[j] < b[j]) {
      if (a[j] < dp[j - 1].first && b[j] > dp[j - 1].first) {
        dp[j] = dp[j - 1];
      } else {
        long long int i1 = bin1(j, a[j]);
        long long int i2 = bin2(j, a[j]);
        long long int i3 = find2(j, a[j]);
        if (i2 == -1 || (i3 < i2 || i3 < i1)) {
          i1 = bin2(j, b[j]);
          i2 = bin1(j, b[j]);
          i3 = find1(j, b[j]);
          if (i2 == -1 || (i3 < i2 || i3 < i1)) {
            dp[j] = {-inf, 0};
          } else {
            dp[j] = {b[j], i3 - max(i1, i2) + 1};
          }
        } else {
          dp[j] = {a[j], i3 - max(i1, i2) + 1};
        }
      }
    } else {
      dp[j] = {-inf, 0};
    }
  }
  long long int ans = 0;
  for (long long int j = 0; j < n; j++) {
    ans += dp[j].second;
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  power[0] = 1;
  for (long long int j = 1; j <= 60; j++) power[j] = power[j - 1] * 2;
  while (t--) {
    solve();
  }
  return 0;
}
long long int bin1(long long int j, long long int m) {
  long long int l = 0, r = j;
  while (r - l + 1 > 2) {
    long long int x = (l + r) / 2;
    if (mx(x, j, 0) <= m) {
      r = x;
    } else {
      l = x;
    }
  }
  if (r - l + 1 == 2) {
    if (mx(l, j, 0) == m) {
      return l;
    } else if (mx(r, j, 0) == m) {
      return r;
    }
  }
  if (r - l + 1 == 1) {
    if (mx(r, j, 0) == m) {
      return r;
    }
  }
  return -1;
}
long long int bin2(long long int j, long long int m) {
  long long int l = 0, r = j;
  while (r - l + 1 > 2) {
    long long int x = (l + r) / 2;
    if (mn(x, j, 0) >= m) {
      r = x;
    } else {
      l = x;
    }
  }
  if (r - l + 1 == 2) {
    if (mn(l, j, 0) == m) {
      return l;
    } else if (mn(r, j, 0) == m) {
      return r;
    }
  }
  if (r - l + 1 == 1) {
    if (mn(r, j, 0) == m) {
      return r;
    }
  }
  return -1;
}
long long int find1(long long int j, long long int m) {
  if (mp1[m].size() == 0) return -1;
  auto it = mp1[m].lower_bound(j);
  if (it == mp1[m].end()) {
    if (*prev(it) <= j) {
      return *prev(it);
    }
    return -1;
  }
  if (*it == j) {
    return j;
  }
  if (it == mp1[m].begin()) {
    return -1;
  }
  if (*prev(it) <= j) {
    return *prev(it);
  }
  return -1;
}
long long int find2(long long int j, long long int m) {
  if (mp2[m].size() == 0) return -1;
  auto it = mp2[m].lower_bound(j);
  if (it == mp2[m].end()) {
    if (*prev(it) <= j) {
      return *prev(it);
    }
    return -1;
  }
  if (*it == j) {
    return j;
  }
  if (it == mp2[m].begin()) {
    return -1;
  }
  if (*prev(it) <= j) {
    return *prev(it);
  }
  return -1;
}
