#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& num) {
  bool start = false, neg = false;
  char c;
  num = 0;
  while ((c = getchar()) != EOF) {
    if (c == '-')
      start = neg = true;
    else if (c >= '0' && c <= '9') {
      start = true;
      num = num * 10 + c - '0';
    } else if (start)
      break;
  }
  if (neg) num = -num;
}
const int maxn = (int)(3e5) + 5;
int ai[maxn], bi[maxn], ci[maxn];
inline void chkmax(int& x, int v) { x = max(x, v); }
int main() {
  int n;
  read(n);
  for (int i = (1); i <= (n); i++) read(ai[i]);
  for (int i = (1); i <= (n); i++) chkmax(bi[1], ai[i]);
  for (int i = (2); i <= (n - 1); i++)
    ci[i] = min(ai[i], max(ai[i - 1], ai[i + 1]));
  int mx = n, sgn = 0;
  if (!(mx & 1)) sgn = 1;
  int l = n / 2 + 1 - sgn, r = n / 2 + 1, now = 0;
  for (int i = mx - sgn; i >= 3; i -= 2) {
    chkmax(now, max(ci[l--], ci[r++]));
    bi[i] = now;
  }
  for (int i = (1); i <= (n - 1); i++) ci[i] = max(ai[i], ai[i + 1]);
  mx = n;
  sgn = 0;
  if (mx & 1) sgn = 1;
  l = n / 2;
  r = n / 2 + sgn;
  now = 0;
  for (int i = mx - sgn; i >= 2; i -= 2) {
    chkmax(now, max(ci[l--], ci[r++]));
    bi[i] = now;
  }
  for (int i = (n); i >= (1); i--) printf("%d ", bi[i]);
  putchar('\n');
  return 0;
}
