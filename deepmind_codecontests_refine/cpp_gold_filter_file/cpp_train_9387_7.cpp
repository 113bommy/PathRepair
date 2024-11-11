#include <bits/stdc++.h>
using namespace std;
namespace prom {
void read(char* s) {
  char a = getchar();
  while (a != '\n' && a != '\r' && a != EOF) *s = a, s++, a = getchar();
  *s = 0;
}
void writ(int x) {
  static int st[22];
  int t = 0;
  bool fl = 0;
  if (x < 0) fl = 1, x = -x;
  if (!x) st[++t] = 0;
  while (x) st[++t] = x % 10, x /= 10;
  if (fl) putchar('-');
  while (t) putchar(st[t--] + '0');
}
const int se = 9973;
char sa[1000005], sb[1000005];
char sreva[1000005], srevb[1000005];
unsigned long long A[1000005], B[1000005];
unsigned long long powse[10000005];
unsigned long long revA[1000005], revB[1000005];
unsigned long long gethash(unsigned long long* h, int l, int r) {
  return h[r] - h[l - 1] * powse[r - l + 1];
}
int maxp[1000005];
int main() {
  read(sa + 1);
  read(sb + 1);
  int lena = strlen(sa + 1), lenb = strlen(sb + 1);
  if (lena != lenb) {
    puts("-1 -1");
    return 0;
  }
  int n = lena;
  for (int i = 1; i <= n; i++)
    sreva[i] = sa[n - i + 1], srevb[i] = sb[n - i + 1];
  powse[0] = 1;
  for (int i = 1; i <= n; i++) powse[i] = powse[i - 1] * se;
  for (int i = 1; i <= n; i++) {
    A[i] = A[i - 1] * se + sa[i];
    revA[i] = revA[i - 1] * se + sreva[i];
    B[i] = B[i - 1] * se + sb[i];
    revB[i] = revB[i - 1] * se + srevb[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = i - 1, r = n, res = i - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (gethash(B, i, mid) == gethash(revA, 1, mid - i + 1))
        res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    maxp[i] = res;
  }
  for (int i = 1; i <= n; i++) maxp[i] = max(maxp[i], maxp[i - 1]);
  for (int i = n - 1; i; i--)
    if (gethash(A, 1, i) == gethash(revB, 1, i)) {
      int l = 1, r = n - i, res = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (gethash(B, 1, mid) == gethash(A, i + 1, i + mid))
          res = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      res++;
      int p = lower_bound(maxp + 1, maxp + res, n - i) - maxp;
      if (maxp[p] >= n - i) {
        printf("%d %d\n", i - 1, i + p - 1);
        return 0;
      }
    }
  puts("-1 -1");
  return 0;
}
}  // namespace prom
int main() { return prom::main(); }
