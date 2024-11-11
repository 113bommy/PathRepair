#include <bits/stdc++.h>
using namespace std;
int v[200002];
int vis[1000004];
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int find(long long int x) {
  if (x == vis[x]) return x;
  return vis[x] = find(vis[x]);
}
bool merge(long long int x, long long int y) {
  long long int a = find(x);
  long long int b = find(y);
  if (a != b) {
    vis[a] = b;
    return true;
  }
  return false;
}
void build(vector<long long int> &tree, long long int i, long long int l,
           long long int r, vector<long long int> &v) {
  if (l == r) {
    tree[i] = v[l];
    return;
  }
  long long int mid = (l + r) / 2;
  build(tree, 2 * i, l, mid, v);
  build(tree, 2 * i + 1, mid + 1, r, v);
  tree[i] = tree[2 * i] + tree[2 * i + 1];
}
long long int get(vector<long long int> &tree, long long int i, long long int l,
                  long long int r, long long int ql, long long int qr,
                  vector<long long int> &lazy) {
  if (lazy[i] != -1) {
    if (lazy[i] == 0) {
      tree[i] = 0;
      if (l != r) {
        lazy[2 * i] = 0;
        lazy[2 * i + 1] = 0;
      }
    } else {
      tree[i] = lazy[i];
      long long int mid = (l + r) / 2;
      if (l != r) {
        lazy[2 * i] = mid - l + 1;
        lazy[2 * i + 1] = r - mid;
      }
    }
    lazy[i] = -1;
  }
  if (ql > r || qr < l) return 0;
  if (ql <= l && r <= qr) return (tree[i]);
  long long int mid = (l + r) / 2;
  return (get(tree, 2 * i, l, mid, ql, qr, lazy) +
          get(tree, 2 * i + 1, mid + 1, r, ql, qr, lazy));
}
void update(vector<long long int> &tree, long long int i, long long int l,
            long long int r, long long int ql, long long int qr,
            long long int val, vector<long long int> &lazy) {
  long long int mid = (l + r) / 2;
  if (ql > r || qr < l)
    return;
  else if (ql <= l && r <= qr) {
    tree[i] = (val == 0) ? 0 : r - l + 1;
    if (l != r) {
      lazy[2 * i] = (val == 0) ? 0 : mid - l + 1;
      lazy[2 * i + 1] = (val == 0) ? 0 : r - mid;
    }
    lazy[i] = -1;
  } else {
    update(tree, 2 * i, l, mid, ql, qr, val, lazy);
    update(tree, 2 * i + 1, mid + 1, r, ql, qr, val, lazy);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
}
long long int make(vector<vector<long long int> > &v, long long int a,
                   long long int b, long long int ini, long long int pre,
                   long long int use) {
  if ((ini + a) % 10 == pre || (ini + b) % 10 == pre) {
    v[ini][pre] = 1;
    return 1;
  }
  if (use > 10) return 10000000000001;
  if (v[ini][pre] != 0) {
    return v[ini][pre];
  } else {
    v[ini][pre] = min(make(v, a, b, (ini + a) % 10, pre, use + 1),
                      make(v, a, b, (ini + b) % 10, pre, use + 1)) +
                  1;
    return v[ini][pre];
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long int a;
  cin >> a;
  if (a % 2 == 0) {
    cout << a - 3 << " 2 "
         << "1" << endl;
  } else {
    for (int i = 2; i < a; i++) {
      if (gcd((a - 1 - i), i) == 1) {
        cout << a - 1 - i << " " << i << " 1" << endl;
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int te = 1;
  cin >> te;
  while (te--) {
    solve();
  }
  return 0;
}
