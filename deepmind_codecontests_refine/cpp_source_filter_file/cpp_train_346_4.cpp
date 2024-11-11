#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
class BIT {
  vector<long long> bit;

 public:
  BIT(int n) : bit(n + 1) {}
  void add(int idx, long long val) {
    idx++;
    while (idx < (int)bit.size()) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  long long sum(int i) {
    long long s = 0;
    i++;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
};
int zz(int z, int i) {
  i++;
  int m = i % (2 * (z - 1));
  if (m == 0) return 2;
  if (m <= z) return m;
  return 2 * z - m;
}
int main() {
  const int n = getInt();
  vector<vector<BIT> > bits(7, vector<BIT>(14, BIT(n)));
  vector<long long> a(n);
  for (int i = 0; i < (int)(n); i++) {
    a[i] = getInt();
  }
  for (int i = 0; i < (int)(7); i++)
    for (int j = 0; j < (int)((i - 1) * 2); j++)
      if (i > 1) {
        for (int k = 0; k < (int)(n); k++) {
          bits[i][j].add(k, zz(i, j + k) * a[k]);
        }
      }
  const int m = getInt();
  for (int cc = 0; cc < (int)(m); cc++) {
    const int t = getInt();
    if (t == 1) {
      const int p = getInt() - 1;
      const int v = getInt();
      for (int i = 0; i < (int)(7); i++)
        for (int j = 0; j < (int)((i - 1) * 2); j++)
          if (i > 1) {
            bits[i][j].add(p, -zz(i, j + p) * a[p]);
            bits[i][j].add(p, zz(i, j + p) * v);
          }
      a[p] = v;
    } else {
      const int l = getInt() - 1;
      const int r = getInt() - 1;
      const int z = getInt();
      for (int i = 0; i < (int)(2 * (z - 1)); i++)
        if (zz(z, i + l) == 1) {
          long long ans = bits[z][i].sum(r);
          if (l != 0) ans -= bits[z][i].sum(l - 1);
          cout << ans << endl;
        }
    }
  }
  return 0;
}
