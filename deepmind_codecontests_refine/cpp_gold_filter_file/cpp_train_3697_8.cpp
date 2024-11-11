#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
const int MAXN = 2005;
long long a[MAXN], b[MAXN], c[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  int zr = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d%I64d", &a[i], &b[i], &c[i]);
    if (c[i] == 0) zr++;
  }
  int res = (zr == 2 ? n - 2 : 0);
  vector<pair<long long, long long> > v;
  for (int i = 0; i < n; i++) {
    if (c[i] == 0) continue;
    v.clear();
    long long px = a[i] * a[i] + b[i] * b[i];
    long long qx = a[i] * c[i];
    long long py = a[i] * a[i] + b[i] * b[i];
    long long qy = b[i] * c[i];
    for (int j = 0; j < i; j++) {
      if (c[j] == 0) continue;
      long long px2 = a[j] * a[j] + b[j] * b[j];
      long long qx2 = a[j] * c[j];
      long long py2 = a[j] * a[j] + b[j] * b[j];
      long long qy2 = b[j] * c[j];
      long long sx = qx * px2 - px * qx2;
      long long sy = qy * py2 - py * qy2;
      long long g = gcd(abs(sx), abs(sy));
      sx /= g;
      sy /= g;
      if (sx < 0 || (sx == 0 && sy < 0)) {
        sx = -sx;
        sy = -sy;
      }
      v.push_back(make_pair(sx, sy));
    }
    sort(v.begin(), v.end());
    int tn = (int)v.size();
    int la = 0;
    for (int i = 0; i < tn; i++)
      if (v[i] != v[la]) {
        res += (i - la) * (i - la - 1) / 2;
        la = i;
      }
    res += (tn - la) * (tn - la - 1) / 2;
  }
  printf("%d\n", res);
  return 0;
}
