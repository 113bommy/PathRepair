#include <bits/stdc++.h>
using namespace std;
struct seg {
  int from;
  int to;
  int cnt;
};
const int MX = 200200;
int64_t a[MX];
int b[MX], c[MX];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i{1}; i <= n; ++i) cin >> a[i];
  int m;
  cin >> m;
  for (int i{0}; i < m; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }
  unordered_set<int64_t> ans;
  int start{1}, finish{1}, dir{1};
  int64_t cur{0};
  c[1] = 1;
  int diff{0};
  for (int i{1}; i <= n; ++i) diff += b[i] != c[i];
  for (int i{0}; i < m - 1; ++i) {
    cur += abs(a[finish + dir] - a[finish]);
    ++c[finish += dir];
    diff += c[finish] - 1 == b[finish];
    diff -= c[finish] == b[finish];
    if (1 == finish or n == finish) dir *= -1;
  }
  if (!diff) ans.insert(cur);
  for (int i{1}; i < n; ++i) {
    cur -= a[start + 1] - a[start];
    --c[start];
    diff += c[start] + 1 == b[start];
    diff -= c[start] == b[start];
    ++start;
    cur += abs(a[finish + dir] - a[finish]);
    ++c[finish += dir];
    diff += c[finish] - 1 == b[finish];
    diff -= c[finish] == b[finish];
    if (1 == finish or n == finish) dir *= -1;
    if (!diff) ans.insert(cur);
  }
  memset(c, 0, sizeof c);
  cur = 0;
  start = n;
  finish = n;
  dir = -1;
  diff = 0;
  c[n] = 1;
  for (int i{1}; i <= n; ++i) diff += c[i] != b[i];
  for (int i{0}; i < m - 1; ++i) {
    cur += abs(a[finish + dir] - a[finish]);
    ++c[finish += dir];
    diff += c[finish] - 1 == b[finish];
    diff -= c[finish] == b[finish];
    if (1 == finish or n == finish) dir *= -1;
  }
  if (!diff) ans.insert(cur);
  for (int i{n - 1}; i > 1; --i) {
    cur -= a[start] - a[start - 1];
    --c[start];
    diff += c[start] + 1 == b[start];
    diff -= c[start] == b[start];
    --start;
    cur += abs(a[finish + dir] - a[finish]);
    ++c[finish += dir];
    diff += c[finish] - 1 == b[finish];
    diff -= c[finish] == b[finish];
    if (1 == finish or n == finish) dir *= -1;
    if (!diff) ans.insert(cur);
  }
  if (ans.size() > 1)
    cout << -1;
  else
    cout << *ans.begin();
}
