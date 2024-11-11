#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int inf = 1e9;
int mod = 1e9 + 7;
vector<int> z_function(string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
struct ST {
  long long int sum;
  int cnt;
  explicit ST(long long int _sum = 0LL, int _cnt = 0) : sum(_sum), cnt(_cnt) {}
};
ST operator+(const ST &A, const ST &B) {
  return (ST(A.sum + B.sum, A.cnt + B.cnt));
}
struct segtree {
  vector<ST> tree;
  explicit segtree(int n = N) { tree.resize(4 * n); }
  void update(int node, int start, int end, int idx, int val, int cnt) {
    if (start == end) {
      tree[node].sum += 1LL * cnt * val;
      tree[node].cnt += cnt;
    } else {
      int mid = (start + end) / 2;
      if (idx <= mid)
        update(2 * node, start, mid, idx, val, cnt);
      else
        update(2 * node + 1, mid + 1, end, idx, val, cnt);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
  ST query(int node, int start, int end, int l, int r) {
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) / 2;
    if (mid >= r) return query(2 * node, start, mid, l, r);
    if (mid < l) return query(2 * node + 1, mid + 1, end, l, r);
    ST P1 = query(2 * node, start, mid, l, r);
    ST P2 = query(2 * node + 1, mid + 1, end, l, r);
    return P1 + P2;
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> m >> n;
  string a, b, s;
  cin >> a >> b >> s;
  string sf;
  for (int i = 0; i < (int)s.length() - 1; i++) sf.push_back(s[i]);
  string sb;
  for (int i = 1; i < (int)s.length(); i++) sb.push_back(s[i]);
  string e = sf + "#" + a;
  vector<int> temp_z = z_function(e);
  vector<int> zf;
  for (int i = n; i < n + m; i++) zf.push_back(temp_z[i]);
  reverse(sb.begin(), sb.end());
  reverse(b.begin(), b.end());
  e = sb + "#" + b;
  temp_z = z_function(e);
  vector<int> zb;
  for (int i = n; i < n + m; i++) zb.push_back(temp_z[i]);
  reverse(zb.begin(), zb.end());
  segtree T(n);
  for (int i = 0; i < min(m, n - 1); i++)
    T.update(1, 0, n - 1, n - zb[i] - 1, zb[i] - n + 1, 1);
  long long int ans = 0;
  for (int i = 0; i < m; i++) {
    ST temp = T.query(1, 0, n - 1, 0, zf[i]);
    ans += 1LL * zf[i] * temp.cnt + temp.sum;
    T.update(1, 0, n - 1, n - zb[i] - 1, zb[i] - n + 1, -1);
    if (i + 1 + n - 2 < m) {
      int x = i + 1 + n - 2;
      T.update(1, 0, n - 1, n - zb[x] - 1, zb[x] - n + 1, 1);
    }
  }
  cout << ans << "\n";
  return 0;
}
