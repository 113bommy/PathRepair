#include <bits/stdc++.h>
const int maxn = 5010;
const int maxm = 3 * 1e5 + 10;
using namespace std;
struct Ca {
  int i;
  int val;
  bool operator<(Ca other) const {
    if (i != other.i)
      return val < other.val;
    else
      return i < other.i;
  }
};
int n, m, k;
int a[maxn], b[maxn], c[maxn], need[maxn], have[maxn], extra[maxn];
vector<int> p[maxn];
set<Ca> greedy;
set<int> visited;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    int t;
    cin >> t;
    int tgt;
    cin >> tgt;
    p[t].push_back(tgt);
  }
  have[1] = k;
  for (int i = 2; i <= n + 1; i++) {
    have[i] = have[i - 1] + b[i - 1];
  }
  need[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    need[i] = max(a[i], need[i + 1] - b[i]);
  }
  for (int i = 1; i <= n + 1; i++) {
    extra[i] = have[i] - need[i];
    if (extra[i] < 0) {
      cout << -1;
      return 0;
    } else {
      for (int j = i + 1; j <= n + 1; j++) {
        have[j] -= extra[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      extra[i] += extra[i + 1];
    else
      extra[i] = extra[i + 1];
  }
  long long tt = 0;
  for (int i = n; i >= 1; i--) {
    greedy.insert((Ca){i, c[i]});
    for (int j = 0; j < p[i].size(); j++) {
      greedy.insert((Ca){p[i][j], c[p[i][j]]});
    }
    while (extra[i] != 0) {
      while (!greedy.empty() &&
             visited.find(greedy.rbegin()->i) != visited.end()) {
        greedy.erase(prev(greedy.end()));
      }
      if (greedy.empty()) {
        break;
      } else {
        visited.insert(greedy.rbegin()->i);
        tt += greedy.rbegin()->val;
        greedy.erase(prev(greedy.end()));
        extra[i]--;
      }
    }
  }
  cout << tt;
  return 0;
}
