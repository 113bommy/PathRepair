#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const long long base = 1000000007LL;
const int N = 500005;
int BIT[N], n, b[N];
pair<int, pair<int, int>> a[N];
void update(int x, int val) {
  for (; x > 0; x -= x & -x) BIT[x] = max(BIT[x], val);
}
int get(int x) {
  int res = 0;
  for (; x <= n; x += x & -x) res = max(res, BIT[x]);
  return res;
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first != b.first ? a.first < b.first
                            : a.second.first > b.second.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second.first;
    b[i] = a[i].second.first;
  }
  for (int i = 1; i <= n; ++i) cin >> a[i].second.second;
  sort(b + 1, b + n + 1);
  sort(a + 1, a + n + 1, cmp);
  int res = 0;
  for (int i = n; i > 0; --i) {
    int pos = lower_bound(b + 1, b + n + 1, a[i].second.first) - b;
    int tmp = get(pos + 1);
    if (tmp > a[i].second.second) ++res;
    update(pos, a[i].second.second);
  }
  cout << res;
  return 0;
}
