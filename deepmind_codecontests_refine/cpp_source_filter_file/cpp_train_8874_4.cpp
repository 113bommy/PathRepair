#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
const long long MB = 20;
const long long MOD = 998244353;
long long cnt[100];
struct SegmentTree {
  vector<long long> a;
  vector<vector<long long>> t;
  long long n;
  SegmentTree(long long x, string& s) {
    n = x;
    t.resize(4, vector<long long>(n << 2));
    a.resize(n);
    for (long long i = 0; i < n; i++) {
      a[i] = s[i] - '0';
    }
    buildTree(1, 0, n);
  }
  void updateVertex(long long v, long long vl, long long vr, long long m) {
    long long x = a[m - 1] ? cnt[a[m - 1] * 10 + a[m]] : 0;
    t[3][v] = (t[3][vl] * t[3][vr] % MOD + t[1][vl] * t[2][vr] * x % MOD) % MOD;
    t[2][v] = (t[3][vl] * t[2][vr] % MOD + t[2][vl] * t[0][vr] * x % MOD) % MOD;
    t[1][v] = (t[1][vl] * t[3][vr] % MOD + t[0][vl] * t[1][vr] * x % MOD) % MOD;
    t[0][v] = (t[1][vl] * t[2][vr] % MOD + t[0][vl] * t[0][vr] * x % MOD) % MOD;
  }
  void buildTree(long long v, long long l, long long r) {
    if (l + 1 == r) {
      t[3][v] = cnt[a[l]];
      t[1][v] = t[2][v] = 1;
      return;
    }
    long long m = (l + r) >> 1;
    long long vl = v << 1;
    long long vr = vl + 1;
    buildTree(vl, l, m);
    buildTree(vr, m, r);
    updateVertex(v, vl, vr, m);
  }
  long long getAns() { return t[3][1]; }
  long long id, val;
  void update(long long i, long long c) {
    id = i;
    val = c;
    updateTree(1, 0, n);
  }
  void updateTree(long long v, long long l, long long r) {
    if (l + 1 == r) {
      a[l] = val;
      t[3][v] = cnt[a[l]];
      return;
    }
    long long m = (l + r) >> 1;
    long long vl = v << 1;
    long long vr = vl + 1;
    if (id < m)
      updateTree(vl, l, m);
    else
      updateTree(vr, m, r);
    updateVertex(v, vl, vr, m);
  }
};
void solve() {
  for (long long one = 0; one < 10; one++) {
    for (long long two = 0; two < 10; two++) {
      cnt[one + two]++;
    }
  }
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  SegmentTree tree(n, s);
  for (long long i = 0; i < m; i++) {
    long long x, d;
    cin >> x >> d;
    x--;
    tree.update(x, d);
    cout << tree.getAns() << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(12);
  srand(time(0));
  long long t = 1;
  while (t--) solve();
}
