#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
pair<pair<int, int>, int> p[maxn];
long long mx[maxn << 3], dp[maxn];
map<int, int> mp;
set<int> st;
int n;
void update(int l, int r, int x, long long val, int id) {
  if (r - l == 1) {
    mx[id] = max(val, mx[id]);
    return;
  }
  int mid = (l + r) >> 1, left = id << 1, right = left | 1;
  if (x < mid)
    update(l, mid, x, val, left);
  else
    update(mid, r, x, val, right);
  mx[id] = max(mx[left], mx[right]);
  return;
}
long long query(int l, int r, int lo, int hi, int id) {
  if (r <= lo || hi <= l) return 0;
  if (l >= lo && r <= hi) return mx[id];
  int mid = (l + r) >> 1, left = id << 1, right = left | 1;
  return max(query(l, mid, lo, hi, left), query(mid, r, lo, hi, right));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first.second >> p[i].first.first >> p[i].second;
    st.insert(p[i].first.second);
    st.insert(p[i].first.first);
  }
  sort(p, p + n);
  int t = 0;
  for (auto i : st) mp[i] = t++;
  for (int i = 0; i < n; ++i) {
    dp[i] = query(0, t, mp[p[i].first.second] + 1, t, 1) + p[i].second;
    update(0, t, mp[p[i].first.first], dp[i], 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
  cout << ans << '\n';
  return 0;
}
