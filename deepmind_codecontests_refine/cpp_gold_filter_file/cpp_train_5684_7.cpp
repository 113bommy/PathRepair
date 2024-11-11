#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000001;
const long long LINF = 1000000000000000001LL;
struct ITree {
  vector<long long> T;
  int p = 1;
  ITree(int n) {
    while (p < n) p *= 2;
    T.resize(2 * p - 1, 0);
  }
  int par(int x) { return (x - 1) / 2; }
  void add(int l, long long v) {
    l += p - 1;
    T[l] += v;
    while (l > 0) {
      l = par(l);
      T[l] += v;
    }
  }
  long long query(int l, int r) {
    l += p - 1;
    r += p - 1;
    long long ans = T[l];
    if (l < r) ans += T[r];
    while (par(l) != par(r)) {
      if (l % 2 == 1) ans += T[l + 1];
      if (r % 2 == 0) ans += T[r - 1];
      l = par(l);
      r = par(r);
    }
    return ans;
  }
};
long long sumFirstValues(int k, int n, ITree &treeHave, ITree &treeVal) {
  if (k < 0)
    return -1;
  else if (k == 0)
    return 0;
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (treeHave.query(0, mid) >= k) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == n) {
    return -1;
  } else {
    return treeVal.query(0, r);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n);
  for (int i = (0); i <= (n - 1); ++i) cin >> c[i];
  vector<pair<int, int> > values(n);
  for (int i = (0); i <= (n - 1); ++i) values[i] = {c[i], i};
  sort(values.begin(), values.end());
  vector<int> pos(n);
  for (int i = (0); i <= ((int)(values).size() - 1); ++i) {
    pos[values[i].second] = i;
  }
  vector<int> type(n, 0);
  for (int person = (0); person <= (1); ++person) {
    int a;
    cin >> a;
    while (a--) {
      int i;
      cin >> i;
      i--;
      type[i] |= (1 << person);
    }
  }
  ITree treeHave(n), treeVal(n);
  vector<pair<int, int> > withType[4];
  for (int i = (0); i <= (n - 1); ++i) {
    int v = values[i].second;
    withType[type[v]].push_back(values[i]);
  }
  for (auto &e : withType[0]) {
    treeHave.add(pos[e.second], 1);
    treeVal.add(pos[e.second], e.first);
  }
  long long must = 0;
  for (int type = (1); type <= (2); ++type)
    for (int i = (0); i <= ((int)(withType[type]).size() - 1); ++i) {
      if (i < k) {
        must += withType[type][i].first;
      } else {
        treeHave.add(pos[withType[type][i].second], 1);
        treeVal.add(pos[withType[type][i].second], withType[type][i].first);
      }
    }
  long long ans = -1;
  for (int i = (0); i <= ((int)(withType[3]).size()); ++i) {
    if (k - i <= min((int)(withType[1]).size(), (int)(withType[2]).size())) {
      int placed = i + 2 * max(0, k - i);
      long long sum = sumFirstValues(m - placed, n, treeHave, treeVal);
      if (sum != -1) {
        sum += must;
        if (ans == -1)
          ans = sum;
        else
          ans = min(ans, sum);
      }
    }
    if (i == (int)(withType[3]).size()) break;
    auto e = withType[3][i];
    must += e.first;
    int ind = k - i - 1;
    if (ind >= 0)
      for (int type = (1); type <= (2); ++type)
        if (ind < (int)(withType[type]).size()) {
          must -= withType[type][ind].first;
          treeHave.add(pos[withType[type][ind].second], 1);
          treeVal.add(pos[withType[type][ind].second],
                      withType[type][ind].first);
        }
  }
  cout << ans;
  return 0;
}
