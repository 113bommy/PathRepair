#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
const int N = 1e5 + 10, xima = INT_MAX;
int n, m, off = 1;
int a[N], t[4 * N];
pair<int, int> t2[4 * N];
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
struct MinT {
  pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
    if (x.first < y.first) {
      return x;
    } else if (x.first > y.first) {
      return y;
    } else {
      return {x.first, y.second + y.second};
    }
  }
  pair<int, int> query(int x, int l, int r, int ml, int mr) {
    if (l > mr || r < ml) return {xima, 0};
    if (l >= ml && r <= mr) {
      return t2[x];
    }
    int mid = (l + r) / 2;
    return merge(query(x * 2, l, mid, ml, mr),
                 query(x * 2 + 1, mid + 1, r, ml, mr));
  }
  void buildTree(int x) {
    if (x >= off) {
      if (x - off >= n) {
        t2[x] = {xima, 0};
      } else {
        t2[x] = {a[x - off], 1};
      }
      return;
    }
    buildTree(2 * x + 1);
    buildTree(2 * x);
    t2[x] = merge(t2[2 * x], t2[2 * x + 1]);
  }
} T;
struct GCDt {
  int merge(int x, int y) {
    if (x == 0) {
      return y;
    } else if (y == 0) {
      return x;
    } else {
      return gcd(x, y);
    }
  }
  int query(int x, int l, int r, int ml, int mr) {
    if (l > mr || r < ml) return 0;
    if (l >= ml && r <= mr) {
      return t[x];
    }
    int mid = (l + r) / 2;
    return merge(query(x * 2, l, mid, ml, mr),
                 query(x * 2 + 1, mid + 1, r, ml, mr));
  }
  void buildTree(int x) {
    if (x >= off) {
      if (x - off >= n) {
        t[x] = 0;
      } else {
        t[x] = a[x - off];
      }
      return;
    }
    buildTree(2 * x + 1);
    buildTree(2 * x);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
  }
} G;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (off < n) {
    off *= 2;
  }
  cin >> m;
  G.buildTree(1);
  T.buildTree(1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    pair<int, int> prvi = T.query(1, 1, off, a, b);
    int drugi = G.query(1, 1, off, a, b);
    if (prvi.first == drugi) {
      cout << (b - a + 1) - prvi.second << endl;
    } else {
      cout << (b - a + 1) << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
