#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
struct RMQ {
  vector<int> t;
  int n;
  RMQ(int n) : n(n) { t.resize(n << 1, 0); }
  void modify(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = (t[p] + t[p ^ 1]);
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
} st(N);
int t[N * 30][2], ptr = 1;
long long aa[33], bb[33];
vector<int> v[N * 30];
void insrt(bitset<30> b, int idx) {
  int cur = 1;
  for (int i = 29; i >= 0; i--) {
    if (!t[cur][b[i]]) {
      t[cur][b[i]] = ++ptr;
    }
    cur = t[cur][b[i]];
    v[cur].push_back(idx);
  }
}
long long calc(vector<int> a, vector<int> b) {
  if (a.empty() || b.empty()) return 0;
  for (int x : a) st.modify(x, 1);
  int ans = 0;
  for (int x : b) {
    ans += st.query(1, x);
  }
  for (int x : a) st.modify(x, 0);
  return ans;
}
void dfs(int cur, int idx) {
  int lft = t[cur][0], rgt = t[cur][1];
  aa[idx] += calc(v[lft], v[rgt]);
  bb[idx] += calc(v[rgt], v[lft]);
  if (idx && lft) dfs(lft, idx - 1);
  if (idx && rgt) dfs(rgt, idx - 1);
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    insrt(bitset<30>(x), i);
  }
  dfs(1, 29);
  long long ans = 0, b = 0;
  for (int i = 29; i >= 0; i--) {
    if (aa[i] < bb[i]) ans ^= (1LL << i);
    b += min(aa[i], bb[i]);
  }
  cout << b << " " << ans << endl;
}
