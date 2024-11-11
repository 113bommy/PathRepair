#include <bits/stdc++.h>
using namespace std;
int n, m, aa, b, c, d;
long long a[100001];
long long z(int s, int x) {
  long long k = (s % (2 * (x - 1)));
  if (!k) return 2ll;
  if (k <= x) return k;
  return 2ll * x - k;
}
struct fenvick_tree {
  long long f[100001];
  void update(int r, long long s) {
    for (int i = r; i <= n; i = (i | (i + 1))) f[i] += s;
  }
  long long sum(int r) {
    long long res = 0ll;
    for (int i = r; i > 0; i = (i & (i + 1)) - 1) res += f[i];
    return res;
  }
  long long getsum(int l, int r) { return sum(r) - sum(l - 1); }
} fen[12][12];
void add(int ind, long long s) {
  a[ind] += s;
  for (int i = 2; i <= 6; ++i)
    for (int j = 1; j <= 2 * (i - 1); ++j)
      fen[i][j].update(ind, s * z(j + ind - 1, i));
}
long long query(int l, int r, int z) {
  int ans = 0;
  for (int i = 1; i <= 2 * (z - 1); ++i)
    if ((i + l - 1) % (2 * (z - 1)) == 1) {
      ans = i;
      break;
    }
  return fen[z][ans].getsum(l, r);
}
int main() {
  scanf("%d", &n);
  long long w;
  for (int i = 1; i <= n; ++i) {
    cin >> w;
    add(i, w);
  }
  scanf("%d", &m);
  while (m--) {
    cin >> aa >> b >> c;
    if (aa == 1)
      add(b, c - a[b]);
    else {
      cin >> d;
      cout << query(b, c, d) << '\n';
    }
  }
}
