#include <bits/stdc++.h>
using namespace std;
struct pr {
  int x, y, i;
} p[200010], q[200010], h[200010];
pr operator-(pr a, pr b) { return {a.x - b.x, a.y - b.y, 0}; }
long long operator*(pr a, pr b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
long long len(pr a) { return (long long)a.x * a.x + (long long)a.y * a.y; }
bool cmp1(pr a, pr b) {
  long long t = a * b;
  return t ? t > 0 : (len(a) < len(b)) ^ (!a.x && !b.x && a.y && b.y);
}
bool cmp2(pr a, pr b) {
  long long t = a * b;
  return t ? t > 0 : len(a) < len(b);
}
int M;
bool cmp(long long v, bool st) { return st ? v <= 0 : v < 0; }
void conv(pr* p, int n, bool st) {
  int i;
  sort(p + 1, p + n + 1, st ? cmp2 : cmp1);
  M = 0;
  for (i = 1; i <= n; i++) {
    while (M > 1 && cmp((h[M] - h[M - 1]) * (p[i] - h[M]), st)) M--;
    h[++M] = p[i];
  }
}
int tp[200010];
int main() {
  int n, m, i;
  bool flag;
  scanf("%d", &n);
  flag = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    if (p[i].x == 0 && p[i].y == 0) flag = 0;
  }
  if (flag) n++;
  for (i = 1; i <= n; i++) p[i].i = i;
  conv(p, n, 0);
  for (i = 2; i <= M; i += 2) tp[h[i].i] = 1;
  for (i = 3; i <= M; i += 2) tp[h[i].i] = 2;
  m = 0;
  for (i = 1; i <= n; i++) {
    if (tp[p[i].i] != 2) q[++m] = p[i];
  }
  conv(q, m, 1);
  for (i = 1; i <= M; i++) {
    if ((h[i].x | h[i].y) & 1) {
      printf("Ani");
      return 0;
    }
  }
  m = 0;
  for (i = 1; i <= n; i++) {
    if (tp[p[i].i] != 1) q[++m] = p[i];
  }
  conv(q, m, 1);
  for (i = 1; i <= M; i++) {
    if ((h[i].x | h[i].y) & 1) {
      printf("Ani");
      return 0;
    }
  }
  printf("Borna");
}
