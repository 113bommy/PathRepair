#include <bits/stdc++.h>
using namespace std;
const int MY = 10000000;
const int MX = 6000;
int n;
int a[2000000];
int f[10000010];
int p[2000000];
int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
int ffget(int a) {
  if (p[a] == a) return a;
  p[a] = ffget(p[a]);
  return p[a];
}
void ffunion(int a, int b) {
  int f1 = ffget(a);
  int f2 = ffget(b);
  if (f1 != f2) p[f2] = f1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[a[i]] = i;
    p[i] = i;
  }
  long long x, y, z;
  bool f1, f2, f3;
  for (int l1 = 1; l1 <= MX; l1++)
    for (int l2 = 1; l2 < l1; l2++) {
      if (((l1 & 1) != (l2 & 1)) && (gcd(l1, l2) == 1)) {
        x = l1 * l1 - l2 * l2;
        y = 2 * l1 * l2;
        z = l1 * l1 + l2 * l2;
        f1 = (x <= MY) && f[x];
        f2 = (y <= MY) && f[y];
        f3 = (z <= MY) && f[z];
        if (f1) {
          if (f2) ffunion(f[x], f[y]);
          if (f3) ffunion(f[x], f[z]);
        }
        if (f1 && f3) ffunion(f[y], f[z]);
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (ffget(i) == i) {
      ans++;
    }
  cout << ans << endl;
  return 0;
}
