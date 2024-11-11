#include <bits/stdc++.h>
int n, m, p;
struct Seat {
  int w;
  int idx;
} a[300000];
char s[600000];
bool cmp(Seat &a, Seat &b) { return a.w < b.w; }
int belong[300000];
int getfa(int x) {
  if (belong[x] != x) belong[x] = getfa(belong[x]);
  return belong[x];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].w);
    a[i].idx = i + 1;
    belong[i] = i;
  }
  std::sort(a, a + n, cmp);
  scanf("%s", s);
  m = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (s[i] == '0') {
      printf("%d ", a[m].idx);
      ++m;
    } else {
      p = getfa(m - 1);
      printf("%d ", a[p].idx);
      belong[p] = p - 1;
    }
  }
  return 0;
}
