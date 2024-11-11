#include <bits/stdc++.h>
int main() {
  int c[5], d[5], h1, h2, m1, m2, t;
  char a[10], b[10];
  gets(a);
  gets(b);
  for (int i = 0; i < 5; i++) {
    c[i] = a[i] - '0';
    d[i] = b[i] - '0';
  }
  h1 = c[0] * 10 + c[1];
  h2 = d[0] * 10 + d[1];
  m1 = c[3] * 10 + c[4];
  m2 = d[3] * 10 + d[4];
  if (h1 == 0) h1 = 24;
  if (h2 == 0) h2 = 24;
  if (m1 < m2) {
    h2 = h2 + 1;
    m1 = m1 + 60;
  }
  t = h1 - h2;
  if (t < 0) t = t + 24;
  printf("%02d:%02d\n", t, m1 - m2);
}
