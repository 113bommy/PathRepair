#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool Max(T1& a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
bool Min(T1& a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
const int N = 400001;
set<int> st[128];
int bit[N];
int mx;
int n;
void add(int i, int v) {
  for (; i <= n; i += i & -i) bit[i] += v;
}
int get(int k) {
  int ans = 0;
  for (int i = mx; i; i >>= 1)
    if (ans + i <= n && bit[ans + i] < k) {
      ans += i;
      k -= bit[ans];
    }
  return ans + 1;
}
void solve() {
  int m, l, r;
  char ch;
  cin >> n >> m;
  for (mx = 1; mx < n; mx <<= 1)
    ;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> ch;
    st[ch].insert(i);
    add(i, 1);
  }
  while (m--) {
    cin >> l >> r >> ch;
    l = get(l);
    r = get(r);
    auto it = st[ch].lower_bound(l);
    while (it != st[ch].end() && *it <= r) {
      add(*it, -1);
      it = st[ch].erase(it);
    }
  }
  vector<pair<int, char>> vec;
  for (int ch = 0; ch < (int)(128); ++ch) {
    for (auto& e : st[ch]) vec.push_back({e, ch});
  }
  sort(vec.begin(), vec.end());
  for (auto& e : vec) cout << e.second;
  cout << '\n';
}
void init() {}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  init();
  int TC = 1;
  for (int TI = 1; TI <= (int)(TC); ++TI) {
    solve();
  }
  return 0;
}
