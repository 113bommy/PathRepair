#include <bits/stdc++.h>
using namespace std;
int T, a[1002], b[1002], a1[1002], a2[1002], b1[1002], b2[1002], h, v;
bitset<1002 * 1002> f[1002];
bool cmp1(int x, int y) { return x < y; }
bool cmp2(int x, int y) { return x > y; }
int main() {
  cin >> T;
  while (T--) {
    scanf("%d", &h);
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= h; i++) scanf("%d", &a[i]), sum1 += a[i];
    scanf("%d", &v);
    for (int i = 1; i <= v; i++) scanf("%d", &b[i]), sum2 += b[i];
    if (sum1 % 2 == 1 || sum2 % 2 == 1 || h != v) {
      printf("NO\n");
      continue;
    }
    sum1 /= 2, sum2 /= 2;
    f[0][0] = 1;
    for (int i = 1; i <= h; i++) {
      f[i] = f[i - 1] | (f[i - 1] << a[i]);
    }
    if (!f[h][sum1]) {
      printf("NO\n");
      continue;
    }
    int lena1 = 0, lena2 = 0, lenb1 = 0, lenb2 = 0;
    for (int i = h; i >= 1; i--) {
      if (sum1 >= a[i] && f[i - 1][sum1 - a[i]])
        a1[++lena1] = a[i], sum1 -= a[i];
      else
        a2[++lena2] = a[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= v; i++) {
      f[i] = f[i - 1] | (f[i - 1] << b[i]);
    }
    if (!f[v][sum2]) {
      printf("NO\n");
      continue;
    }
    for (int i = v; i >= 1; i--) {
      if (sum2 >= b[i] && f[i - 1][sum2 - b[i]])
        b1[++lenb1] = b[i], sum2 -= b[i];
      else
        b2[++lenb2] = b[i];
    }
    sort(a1 + 1, a1 + lena1 + 1, cmp2);
    sort(a2 + 1, a2 + lena2 + 1, cmp2);
    sort(b1 + 1, b1 + lenb1 + 1, cmp1);
    sort(b2 + 1, b2 + lenb2 + 1, cmp1);
    if (lena1 > lena2) swap(lena1, lena2), swap(a1, a2);
    if (lenb1 < lenb2) swap(lenb1, lenb2), swap(b1, b2);
    int x = 0, y = 0;
    printf("YES\n");
    for (int i = 1; i <= h; i++) {
      if (i <= lena1)
        x += a1[i];
      else
        x -= a2[i - lena1];
      printf("%d %d\n", x, y);
      if (i <= lenb1)
        y += b1[i];
      else
        y -= b2[i - lenb1];
      printf("%d %d\n", x, y);
    }
  }
}
