#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 5;
long long tree[MAX] = {0};
long long lazy[MAX] = {0};
void updateRangeUtil(long long si, long long ss, long long se, long long us,
                     long long ue, long long diff) {
  if (lazy[si] != 0) {
    tree[si] += lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > ue || se < us) return;
  if (ss >= us && se <= ue) {
    tree[si] += diff;
    if (ss != se) {
      lazy[si * 2 + 1] += diff;
      lazy[si * 2 + 2] += diff;
    }
    return;
  }
  long long mid = (ss + se) / 2;
  updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
  updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
  tree[si] = min(tree[si * 2 + 1], tree[si * 2 + 2]);
}
void updateRange(long long n, long long us, long long ue, long long diff) {
  updateRangeUtil(0, 0, n - 1, us, ue, diff);
}
long long getSumUtil(long long ss, long long se, long long qs, long long qe,
                     long long si) {
  if (lazy[si] != 0) {
    tree[si] += lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > qe || se < qs) return 1000000000;
  if (ss >= qs && se <= qe) return tree[si];
  long long mid = (ss + se) / 2;
  return min(getSumUtil(ss, mid, qs, qe, 2 * si + 1),
             getSumUtil(mid + 1, se, qs, qe, 2 * si + 2));
}
long long getSum(long long n, long long qs, long long qe) {
  return getSumUtil(0, n - 1, qs, qe, 0);
}
void constructSTUtil(long long arr[], long long ss, long long se,
                     long long si) {
  if (ss > se) return;
  if (ss == se) {
    tree[si] = arr[ss];
    return;
  }
  long long mid = (ss + se) / 2;
  constructSTUtil(arr, ss, mid, si * 2 + 1);
  constructSTUtil(arr, mid + 1, se, si * 2 + 2);
  tree[si] = min(tree[si * 2 + 1], tree[si * 2 + 2]);
}
void constructST(long long arr[], long long n) {
  constructSTUtil(arr, 0, n - 1, 0);
}
struct query {
  long long first, second, idx;
  query(long long _a, long long _b, long long _idx) {
    first = _a;
    second = _b;
    idx = _idx;
  }
};
struct comp {
  bool operator()(const query &a, const query &b) {
    return a.second < b.second;
  }
};
bool cmp(query &a, query &b) { return a.first < b.first; }
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  vector<query> queries;
  for (i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    queries.emplace_back(a - 1, b - 1, i);
  }
  sort(queries.begin(), queries.end(), cmp);
  constructST(a, n);
  multiset<query, comp> pq;
  set<long long> muow;
  long long ans = 0;
  long long ptr = 0;
  for (i = 0; i < m; i++) muow.insert(i);
  for (auto i : queries) updateRange(n, i.first, i.second, -1);
  set<long long> res;
  for (i = 0; i < n; i++) {
    while (ptr < m && i == queries[ptr].first) {
      updateRange(n, queries[ptr].first, queries[ptr].second, 1);
      pq.insert(queries[ptr]);
      muow.erase(queries[ptr].idx);
      ++ptr;
    }
    while (!pq.empty() && (i == (1 + pq.begin()->second))) {
      query x = *pq.begin();
      updateRange(n, x.first, x.second, -1);
      muow.insert(x.idx);
      pq.erase(pq.begin());
    }
    if (ans < a[i] - getSum(n, 0, n - 1)) res = muow;
    ans = max(ans, a[i] - getSum(n, 0, n - 1));
  }
  cout << ans << "\n";
  cout << res.size() << "\n";
  for (auto i : res) cout << i + 1 << " ";
  cout << "\n";
  return 0;
}
