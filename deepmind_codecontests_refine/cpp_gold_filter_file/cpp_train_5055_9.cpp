#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 2e5 + 500;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
struct nop {
  long long sum, minf, minz;
};
void pri(nop a) {
  cout << "SUM::" << a.sum << "  minz::" << a.minz << "  minf::" << a.minf
       << endl;
}
nop seg[maxn * 8];
long long lazy[maxn * 8];
void add(long long node, long long val, bool zoj) {
  lazy[node] += val;
  seg[node].sum -= (val * zoj);
  seg[node].minf += val;
}
void shift(long long node, long long l, long long r) {
  if (lazy[node] == 0) {
    return;
  }
  long long mid = (r + l) / 2;
  add(2 * node, lazy[node], (mid - l) % 2);
  add(2 * node + 1, lazy[node], (r - mid) % 2);
  lazy[node] = 0;
}
nop merg(nop a, long long la, long long ra, nop b, long long lb, long long rb) {
  nop k;
  if ((rb - lb) % 2 == 0) {
    k.sum = a.sum + b.sum;
  } else {
    k.sum = b.sum - a.sum;
  }
  if ((ra - la) % 2 == 0) {
    k.minf = min(a.minf, b.minf + a.sum);
    k.minz = min(a.minz, b.minz - a.sum);
  } else {
    k.minf = min(a.minf, b.minz - a.sum);
    k.minz = min(a.minz, b.minf + a.sum);
  }
  return k;
}
nop finds(long long L, long long R, long long node, long long l, long long r) {
  if (l <= L && R <= r) {
    return seg[node];
  }
  long long mid = (L + R) / 2;
  shift(node, L, R);
  if (l < mid && mid < r) {
    nop e = finds(L, mid, 2 * node, l, r);
    nop ee = finds(mid, R, 2 * node + 1, l, r);
    return merg(e, max(L, l), mid, ee, mid, min(R, r));
  }
  if (l < mid) {
    return finds(L, mid, 2 * node, l, r);
  }
  return finds(mid, R, 2 * node + 1, l, r);
}
void update(long long L, long long R, long long node, long long l, long long r,
            long long val) {
  if (l <= L && R <= r) {
    add(node, val, (R - L) % 2);
    return;
  }
  if (r <= L || R <= l) {
    return;
  }
  long long mid = (L + R) / 2;
  shift(node, L, R);
  update(L, mid, 2 * node, l, r, val);
  update(mid, R, 2 * node + 1, l, r, val);
  seg[node] = merg(seg[2 * node], L, mid, seg[2 * node + 1], mid, R);
}
int main() {
  for (long long i = 0; i < maxn * 8; i++) {
    seg[i].sum = 0;
    seg[i].minz = 0;
    seg[i].minf = 0;
  }
  long long n, m;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    update(0, n, 1, i, i + 1, v);
  }
  cin >> m;
  for (long long iq = 0; iq < m; iq++) {
    long long noe;
    cin >> noe;
    if (noe == 1) {
      long long l, r, val;
      cin >> l >> r >> val;
      update(0, n, 1, l, r + 1, val);
    } else {
      long long l, r;
      cin >> l >> r;
      nop k = finds(0, n, 1, l, r + 1);
      if ((r - l) % 2 == 0) {
        if (k.minf >= 1 && k.minz >= 0 && k.sum == -1) {
          cout << "1\n";
        } else {
          cout << "0\n";
        }
      } else {
        if (k.minf >= 1 && k.minz >= 0 && k.sum == 0) {
          cout << "1\n";
        } else {
          cout << "0\n";
        }
      }
    }
  }
}
