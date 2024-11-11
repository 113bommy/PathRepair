#include <bits/stdc++.h>
using namespace std;
int n, m, nn, mm, x, y, r, a1, a2, p[1000000], q[1000000];
char s[1000000], t[1000000], ch;
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  ch = 'a';
  for (int i = (1); i <= (500000); i++) {
    if (s[i] != ch) {
      n++;
      p[n] = x;
      x = 0;
      ch = 'a' + 'b' - ch;
    }
    x++;
    if (!s[i]) break;
  }
  ch = 'b';
  x = 0;
  for (int i = (1); i <= (500000); i++) {
    if (t[i] != ch) {
      m++;
      q[m] = x;
      x = 0;
      ch = 'a' + 'b' - ch;
    }
    x++;
    if (!t[i]) break;
  }
  if ((!p[1]) && (!q[1])) {
    n--;
    for (int i = (1); i <= (n); i++) p[i] = p[i + 1];
    m--;
    for (int i = (1); i <= (m); i++) q[i] = q[i + 1];
  }
  nn = n;
  mm = m;
  if (m - n > 2) {
    r = (m - n + 1) / 4 * 2;
    mm -= r + 1;
    nn += r - 1;
    if (nn == r) nn++;
  } else if (n - m > 2) {
    r = (n - m + 1) / 4 * 2;
    nn -= r + 1;
    mm += r - 1;
    if (mm == r) mm++;
  }
  if (((nn - mm) < 0 ? -(nn - mm) : (nn - mm)) > 1) {
    if (!p[1]) {
      n--;
      for (int i = (1); i <= (n); i++) p[i] = p[i + 1];
      m++;
      for (int i = (m + 1); i >= (2); i--) q[i] = q[i - 1];
      q[1] = 0;
    } else if (!q[1]) {
      m--;
      for (int i = (1); i <= (m); i++) q[i] = q[i + 1];
      n++;
      for (int i = (n + 1); i >= (2); i--) p[i] = p[i - 1];
      p[1] = 0;
    }
  }
  if (m - n > 2) {
    r = (m - n + 1) / 4 * 2;
    x = 0;
    for (int i = (1); i <= (r + 1); i++) x += q[i];
    a1 = p[1];
    a2 = x;
    x = p[1];
    y = q[r + 1];
    for (int i = (n + r - 1); i >= (r + 1); i--) p[i] = p[i - r + 1];
    for (int i = (1); i <= (r); i++) p[i] = q[i];
    for (int i = (1); i <= (m - r - 1); i++) q[i] = q[i + r + 1];
    p[r + 1] += y;
    q[1] += x;
    m -= r + 1;
    n += r - 1;
    if (n == r) n++;
  } else if (n - m > 2) {
    r = (n - m + 1) / 4 * 2;
    x = 0;
    for (int i = (1); i <= (r + 1); i++) x += p[i];
    a1 = x;
    a2 = q[1];
    x = q[1];
    y = p[r + 1];
    for (int i = (m + r - 1); i >= (r + 1); i--) q[i] = q[i - r + 1];
    for (int i = (1); i <= (r); i++) q[i] = p[i];
    for (int i = (1); i <= (n - r - 1); i++) p[i] = p[i + r + 1];
    q[r + 1] += y;
    p[1] += x;
    n -= r + 1;
    m += r - 1;
    if (m == r) m++;
  }
  x = y = 0;
  printf("%d\n", (r > 0) + ((n) > (m) ? (n) : (m)) - 1);
  if (r) printf("%d %d\n", a1, a2);
  p[n + 1] = p[n + 2] = q[m + 1] = q[m + 2] = 0;
  for (int i = (1); i <= (((n) > (m) ? (n) : (m)) - 1); i++) {
    x += p[i];
    y += q[i];
    printf("%d %d\n", x, y);
    x ^= y;
    y ^= x;
    x ^= y;
  }
}
