#include <bits/stdc++.h>
using namespace std;
struct CHT {
  vector<long long> m, b;
  long long ptr = 0;
  bool bad(long long l1, long long l2, long long l3) {
    return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2]) <=
           1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]);
  }
  void add(long long _m, long long _b) {
    m.push_back(_m);
    b.push_back(_b);
    long long s = m.size();
    while (s >= 3 && bad(s - 1, s - 2, s - 3)) {
      s--;
      m.erase(m.end() - 2);
      b.erase(b.end() - 2);
    }
  }
  long long f(long long i, long long x) { return m[i] * x + b[i]; }
  long long query(long long x) {
    if (ptr >= m.size()) ptr = m.size() - 1;
    while (ptr < m.size() - 1 && f(ptr + 1, x) < f(ptr, x)) ptr++;
    return f(ptr, x);
  }
};
const long long N = 1e5 + 7;
long long a[N], A[N];
vector<pair<long long, long long> > lines[4 * N];
vector<pair<long long, long long> > queries[4 * N];
long long ans[N];
long long ex[N];
void AddLine(long long u, long long st, long long en, long long idx,
             pair<long long, long long> line) {
  lines[u].push_back(line);
  if (st == en) return;
  long long mid = (st + en) / 2;
  if (idx <= mid)
    AddLine(2 * u, st, mid, idx, line);
  else
    AddLine(2 * u + 1, mid + 1, en, idx, line);
}
void AddQuery(long long u, long long st, long long en, long long l, long long r,
              pair<long long, long long> q) {
  if (r < st || en < l)
    return;
  else if (l <= st && en <= r) {
    queries[u].push_back(q);
  } else {
    long long mid = (st + en) / 2;
    AddQuery(2 * u, st, mid, l, r, q);
    AddQuery(2 * u + 1, mid + 1, en, l, r, q);
  }
}
void push(long long u, long long st, long long en) {
  sort(lines[u].rbegin(), lines[u].rend());
  sort(queries[u].begin(), queries[u].end());
  CHT cht;
  for (pair<long long, long long> pr : lines[u]) cht.add(pr.first, pr.second);
  for (pair<long long, long long> pr : queries[u])
    ans[pr.second] = min(ans[pr.second], (long long)cht.query(pr.first));
  if (st == en) return;
  long long mid = (st + en) / 2;
  push(2 * u, st, mid);
  push(2 * u + 1, mid + 1, en);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    A[i] = A[i - 1] + a[i];
    pair<long long, long long> l = {-a[i], i * a[i] - A[i]};
    AddLine(1, 1, n, i, l);
  }
  long long q;
  cin >> q;
  for (long long i = 1; i <= q; i++) {
    long long x, y;
    cin >> x >> y;
    AddQuery(1, 1, n, y - x + 1, y, {y - x, i});
    ex[i] = A[y];
  }
  for (long long i = 1; i <= q; i++) ans[i] = 2e18;
  push(1, 1, n);
  for (long long i = 1; i <= q; i++) cout << ans[i] + ex[i] << "\n";
}
