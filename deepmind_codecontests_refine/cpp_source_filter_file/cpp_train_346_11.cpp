#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
struct SegTree {
  long long* t;
  void build(long long pos, long long L, long long R, long long a[]) {
    if (L > R) return;
    if (L == R)
      t[pos] = a[L];
    else {
      long long Mid = (L + R) / 2;
      build(pos * 2, L, Mid, a);
      build(pos * 2 + 1, Mid + 1, R, a);
      t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
  }
  long long get(long long pos, long long tl, long long tr, long long L,
                long long R) {
    if (L > R) return 0;
    if (L == tl && R == tr) return t[pos];
    long long Mid = (tl + tr) / 2;
    long long i = get(pos * 2, tl, Mid, L, min(Mid, R));
    long long j = get(pos * 2 + 1, Mid + 1, R, max(L, Mid + 1), R);
    return i + j;
  }
  void update(long long pos, long long tl, long long tr, long long P,
              long long val) {
    if (tl == tr)
      t[pos] = val;
    else {
      long long Mid = (tl + tr) / 2;
      if (P <= Mid)
        update(pos * 2, tl, Mid, P, val);
      else
        update(pos * 2 + 1, Mid + 1, tr, P, val);
      t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
  }
} t[7][14];
long long aa[100001], bb[100001], A[7][14][100001], C[7][100001];
int main(void) {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> aa[i];
  }
  for (int i = 2; i <= 6; i++) {
    for (int y = 1; y <= i; y++) {
      long long u = 1, h = y - 1;
      for (int j = 0; j <= n; j++) {
        h += u;
        if (h == i) u = -1;
        if (h == 1) u = 1;
        bb[j] = h * aa[j];
        A[i][y][j] = h;
        if (h == 1) C[i][j] = y;
      }
      t[i][y].t = new long long[4 * n + 1];
      t[i][y].build(1, 0, n - 1, bb);
    }
    for (int y = 1; y < i; y++) {
      long long u = -1, h = i - y + 1;
      for (int j = 0; j <= n; j++) {
        h += u;
        if (h == i) u = -1;
        if (h == 1) u = 1;
        bb[j] = h * aa[j];
        A[i][y + i][j] = h;
        if (h == 1) C[i][j] = y + i;
      }
      t[i][i + y].t = new long long[4 * n + 1];
      t[i][i + y].build(1, 0, n - 1, bb);
    }
  }
  long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long T;
    cin >> T;
    if (T == 1) {
      long long a, b;
      cin >> a >> b;
      a--;
      for (int j = 2; j <= 6; j++) {
        for (int y = 1; y <= j; y++) {
          t[j][y].update(1, 0, n - 1, a, b * A[j][y][a]);
        }
        for (int y = 1; y < j; y++) {
          t[j][j + y].update(1, 0, n - 1, a, b * A[j][j + y][a]);
        }
      }
    } else {
      long long a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      long long w1 = C[c][a];
      cout << t[c][w1].get(1, 0, n - 1, a, b) << endl;
    }
  }
  return 0;
}
