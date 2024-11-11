#include <bits/stdc++.h>
using namespace std;
constexpr int nmax = 755;
long long v[nmax];
int ans[200005];
int n, m;
vector<tuple<long long, long long> > queries;
int query(long long q) {
  int skipped = 0;
  priority_queue<int> S;
  for (int i = 1; i <= n; i++) {
    q += v[i];
    if (v[i] < 0) S.push(-v[i]);
    if (q < 0) {
      q += S.top();
      S.pop();
      skipped++;
    }
  }
  return skipped;
}
void solve(int query_left, int query_right, int ans_left, int ans_right) {
  if (ans_left == ans_right) {
    for (int i = query_left; i <= query_right; i++) {
      ans[get<1>(queries[i])] = ans_left;
    }
    return;
  }
  long long mid = (query_left + query_right) / 2;
  long long tmpAns;
  tmpAns = ans[get<1>(queries[mid])] = query(get<0>(queries[mid]));
  if (query_left < mid) solve(query_left, mid - 1, tmpAns, ans_right);
  if (mid < query_right) solve(mid + 1, query_right, ans_left, tmpAns);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= m; i++) {
    long long q;
    cin >> q;
    queries.emplace_back(q, i - 1);
  }
  sort(queries.begin(), queries.end());
  solve(0, m - 1, 0, n - 1);
  for (int i = 0; i < m; i++) cout << ans[i] << '\n';
  return 0;
}
