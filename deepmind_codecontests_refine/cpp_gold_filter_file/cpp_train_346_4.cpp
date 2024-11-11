#include <bits/stdc++.h>
using namespace std;
long long ar[100010];
long long st[30][400010];
long long t1[] = {0, 2, 6, 12, 20};
void buildTree(long long id, long long mod, long long v, long long l,
               long long r) {
  if (l == r) {
    st[id + l % mod][v] = ar[l];
    return;
  }
  buildTree(id, mod, 2 * v, l, (l + r) / 2);
  buildTree(id, mod, 2 * v + 1, (l + r) / 2 + 1, r);
  for (long long i = 0; i < mod; ++i)
    st[id + i][v] = st[id + i][2 * v] + st[id + i][2 * v + 1];
}
void update(long long id, long long v, long long l, long long r,
            long long pos) {
  if (l == r) {
    st[id][v] = ar[pos];
    return;
  }
  long long m = (l + r) / 2;
  if (pos <= m)
    update(id, 2 * v, l, m, pos);
  else
    update(id, 2 * v + 1, m + 1, r, pos);
  st[id][v] = st[id][2 * v] + st[id][2 * v + 1];
}
long long get(long long id, long long v, long long tl, long long tr,
              long long l, long long r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return st[id][v];
  long long tm = (tl + tr) / 2;
  return get(id, 2 * v, tl, tm, l, min(r, tm)) +
         get(id, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
long long n;
long long br[100][100];
int main(int argc, char** argv) {
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> ar[i];
  for (long long i = 2; i <= 6; ++i) {
    for (long long j = 1; j <= 2 * (i - 1); ++j) {
      long long t = j % (2 * (i - 1));
      if (t == 0)
        br[i][j] = 2;
      else if (t <= i)
        br[i][j] = t;
      else if (t > i)
        br[i][j] = 2 * i - t;
    }
  }
  for (long long i = 2; i <= 6; ++i)
    buildTree(t1[i - 2], 2 * (i - 1), 1, 0, n - 1);
  long long m;
  cin >> m;
  for (long long count = 0; count < m; ++count) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long p, v;
      cin >> p >> v;
      --p;
      ar[p] = v;
      for (long long i = 2; i <= 6; ++i)
        update(t1[i - 2] + p % (2 * i - 2), 1, 0, n - 1, p);
    } else {
      long long l, r, z;
      cin >> l >> r >> z;
      --l;
      --r;
      long long ans = 0;
      for (long long i = l; i < min(l + 2 * z - 2, r + 1); ++i) {
        ans += ((long long)br[z][i - l + 1]) *
               get(t1[z - 2] + i % (2 * (z - 1)), 1, 0, n - 1, l, r);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
