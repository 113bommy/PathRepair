#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 13;
int count_bits(int x) {
  int cnt = 0;
  for (int i = 0; (1 << i) <= x; i++) {
    if ((1 << i) & x) cnt++;
  }
  return cnt;
}
int bits(int x) {
  int i;
  for (i = 0; (1 << i) <= x; i++)
    if ((1 << i) & x) return i;
  return 0;
}
int main(int argc, const char* argv[]) {
  int n, m, a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE], ca[MAX_SIZE], cb[MAX_SIZE];
  int suma, sumb;
  memset(c, 0, sizeof(c));
  memset(ca, 0, sizeof(ca));
  memset(cb, 0, sizeof(cb));
  int x, y, t = 0;
  suma = sumb = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[i] = (1 << x) | (1 << y);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    b[i] = (1 << x) | (1 << y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j])
        continue;
      else if (a[i] & b[j]) {
        t = a[i] & b[j];
        c[bits(t)] = 1;
        ca[i] |= t;
        ca[i] |= t;
        suma++;
        sumb++;
      }
    }
  }
  bool found = false;
  for (int k = 1; k < 10; k++) {
    for (int i = 0; i < n && !found; i++)
      if (count_bits(ca[i]) > 1) {
        found = true;
      }
    for (int i = 0; i < m && !found; i++)
      if (count_bits(cb[i]) > 1) {
        found = true;
      }
    if (found) {
      printf("-1");
      break;
    }
  }
  if (!found) {
    int cnt = 0;
    t = -1;
    for (int i = 0; i < 10; i++)
      if (c[i]) {
        cnt++;
        t = i;
      }
    printf("%d", cnt == 1 ? t : 0);
  }
  return 0;
}
