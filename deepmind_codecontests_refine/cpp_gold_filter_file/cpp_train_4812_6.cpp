#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, -1};
long long int m, k, n, a[50005], b[50005];
string s1 = "one", s2 = "zero", ch = "", s;
set<long long int> st;
vector<pair<long long int, long long int> > vv, vv2, vm;
vector<pair<pair<long long int, long long int>, long long int> > vvv1, vvv2;
vector<long long int> v, vc;
long long int tree[500005];
void build(long long int node, long long int start, long long int end) {
  if (start == end) {
    tree[node] = b[start];
  } else {
    long long int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}
long long int query(long long int node, long long int start, long long int end,
                    long long int l, long long int r) {
  if (r < start or l > end) return 5e9;
  if (l <= start && r >= end) return tree[node];
  long long int mid = (start + end) / 2;
  long long int p1 = query(2 * node, start, mid, l, r);
  long long int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return min(p1, p2);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int i = 0, x, y, j = 0, z, q, nb0 = 0, nbp = 0, nbn = 0, nbmax = 0,
                nbinf = 0, nb2 = 0, mm = 5e8, idx = 0, ok = 0, l, r,
                negatif = 0, positif = 0, l1, r1, t;
  set<long long int>::iterator it, it2;
  char c;
  cin >> q;
  while (q--) {
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) cin >> a[i];
    k = min(k, m - 1);
    long long int rest = m - k;
    long long int res = -1;
    l = 1;
    r = n;
    for (i = 0; i <= (m - 1); i++) {
      long long int l1 = 1 + i;
      long long int r1 = n - (m - 1 - i);
      b[i + 1] = max(a[l1], a[r1]);
    }
    build(1, 1, m);
    for (i = 0; i <= k; i++) {
      long long int l1 = 1 + i;
      long long int r1 = l1 + rest - 1;
      res = max(res, query(1, 1, m, l1, r1));
    }
    cout << res << endl;
  }
  return 0;
}
