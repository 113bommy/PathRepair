#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(int &x, int y) {
  if (x > y) x = y;
}
inline int read() {
  char s;
  int k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    printf("0");
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
int n, x[3];
const int maxn = 3e5 + 100;
struct node {
  long long w, id;
} a[maxn];
bool cmp(node aa, node bb) { return aa.w < bb.w; }
int main() {
  n = read();
  x[1] = read();
  x[2] = read();
  for (int i = 1; i <= n; i++) a[i].w = read(), a[i].id = i;
  sort(a + 1, a + n + 1, cmp);
  int z;
  for (int i = n - 1; i >= 1; i--) {
    if (x[1] >= (long long)a[i].w * (long long)(n - i + 1) &&
        x[2] >= (n - i + 1) * a[i].w)
      continue;
    z = ceil((double)x[1] / a[i].w);
    if (z < n - i + 1) {
      if (x[2] <= (long long)a[i + z].w * (n - i + 1 - z)) {
        printf("Yes\n");
        printf("%d %d\n", z, n - i + 1 - z);
        for (int j = 1; j <= z; j++) printf("%d ", a[i + j - 1].id);
        putchar('\n');
        for (int j = z + 1; j <= n - i + 1; j++) printf("%d ", a[i + j - 1].id);
        putchar('\n');
        return 0;
      }
    }
    z = ceil((double)x[2] / a[i].w);
    if (z < n - i + 1) {
      if (x[0] <= (long long)a[i + z].w * (n - i + 1 - z)) {
        printf("Yes\n");
        printf("%d %d\n", n - i + 1 - z, z);
        for (int j = z + 1; j <= n - i + 1; j++) printf("%d ", a[i + j - 1].id);
        putchar('\n');
        for (int j = 1; j <= z; j++) printf("%d ", a[i + j - 1].id);
        putchar('\n');
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
