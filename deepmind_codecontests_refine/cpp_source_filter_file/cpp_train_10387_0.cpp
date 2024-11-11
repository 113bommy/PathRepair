#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
template <typename T> 
struct SegmentTree {
  
  int n;
  vector<T> node;

  T f(T a, T b) {return max(a, b);}
  void g(T &a, T b) {a = b;}

  SegmentTree (int sz, T init = 0) {
    n = 1; while (n < sz) n <<= 1;
    node.assign(2*n, init);
    for (int i = n - 2; i >= 0; i--) node[i] = f(node[2*i+1], node[2*i+2]);
  }

  void update(int k, T x) {
    k += (n - 1);
    g(node[k], x);
    while (k > 0) {
      k = (k - 1) >> 1;
      node[k] = f(node[2*k+1], node[2*k+2]);
    } 
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return node[k];
    T vl = query(a, b, 2*k+1, l, (l+r)/2);
    T vr = query(a, b, 2*k+2, (l+r)/2, r);
    return f(vl, vr);
  }

  T getvalue(int k) {
    return query(k,k+1);
  }

  template <typename F> 
  int find (int a, int b, T x, F &ok, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (l + 1 == r) return (ok(node[k]) ? k - n + 1 : b);
    if (!ok(node[k]) || r <= a || b <= l) return b;
    int vl = find(a, b, x, ok, 2*k+1, l, (l + r)/2);
    if (vl != b) return vl;
    return find(a, b, x, ok, 2*k+2, (l + r)/2, r);
  }
 
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  SegmentTree<int> seg(n);
  rep(i,n) {
    int a;
    cin >> a;
    seg.update(i, a);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v; x--;
      seg.update(x, v);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r; l--;
      
      cout << seg.query(l, r) << "\n";
    } else {
      int x, v;
      cin >> x >> v; x--;
      /*
      auto ok = [&](int a) {return a >= v;};
      cout << seg.find(x, n, v, ok) + 1 << "\n";
      */
      int l = x, r = n + 1;
      while (r - l > 1) {
        int m = (r + l) / 2;
        if (seg.query(x, m) >= v) r = m;
        else l = m;
      }
      cout << r << "\n;
    }
  }
  return 0; 
}
