#include <bits/stdc++.h>
using namespace std;
const long long int mod = (long long int)(1e9 + 7);
long long int test = 1;
vector<long long int> read(int n) {
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
void solve() {
  long long int i, j, k, n, t, m, cnt = 0, ans = 0, sum = 0;
  long long int cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<long long int> st(cl);
  for (auto &it : st) {
    cin >> it;
  }
  vector<long long int> el = read(ce);
  long long int q;
  cin >> q;
  while (q--) {
    long long int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    if (x == x1) {
      cout << abs(y - y1) << "\n";
      continue;
    }
    swap(x, y);
    swap(x1, y1);
    ans = INT_MAX;
    if (el.size()) {
      auto ele = lower_bound(el.begin(), el.end(), x) - el.begin();
      if (ele != el.size()) {
        long long int dy = abs(y - y1) / v + (abs(y - y1) % v ? 1 : 0);
        long long int dx = abs(el[ele] - x);
        dx += abs(el[ele] - x1);
        ans = min(ans, dx + dy);
      }
      if (ele != 0) {
        ele--;
        long long int dy = abs(y - y1) / v + (abs(y - y1) % v ? 1 : 0);
        long long int dx = abs(el[ele] - x);
        dx += abs(el[ele] - x1);
        ans = min(ans, dx + dy);
      }
    }
    if (st.size()) {
      auto sta = lower_bound(st.begin(), st.end(), x) - st.begin();
      if (sta != st.size()) {
        long long int dy = abs(y - y1);
        long long int dx = abs(st[sta] - x);
        dx += abs(st[sta] - x1);
        ans = min(ans, dx + dy);
      }
      if (sta != 0) {
        sta--;
        long long int dy = abs(y - y1);
        long long int dx = abs(st[sta] - x);
        dx += abs(st[sta] - x1);
        ans = min(ans, dx + dy);
      }
    }
    cout << ans << "\n";
  }
  test++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i = 1;
  solve();
  return 0;
}
