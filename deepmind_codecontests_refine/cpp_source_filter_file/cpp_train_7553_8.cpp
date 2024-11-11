#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
  char name[25];
  int a;
};
struct node s[N], c[N];
bool cmp(const node x, const node y) {
  if (x.a != y.a) return x.a > y.a;
  return strcmp(x.name, y.name) < 0;
}
int n, m, b[N], os;
char st[30];
int findmax() {
  for (int i = 1; i <= n; i++) {
    c[i] = s[i];
  }
  int i = n, j = m - 1, tmp = 1;
  c[os].a += b[m];
  while (i >= tmp && j > 0) {
    if (i == os) {
      i--;
      continue;
    }
    if (c[i].a + b[j] < c[os].a ||
        (c[i].a + b[j] == c[os].a && strcmp(c[i].name, c[os].name) > 0)) {
      c[i].a += b[j];
      i--;
      j--;
    } else {
      c[tmp].a += b[j];
      tmp++;
      j--;
    }
  }
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (strcmp(c[i].name, st) == 0) return i;
  }
}
int findmin() {
  for (int i = 1; i <= n; i++) {
    c[i] = s[i];
  }
  int j = 1, i = 1;
  if (m == n) {
    c[i].a += b[1];
    j++;
  }
  while (i <= n && j <= m) {
    if (i == os) {
      i++;
      continue;
    }
    if (c[i].a > c[os].a ||
        (c[i].a == c[os].a && strcmp(c[i].name, c[os].name) < 0)) {
      i++;
      continue;
    }
    if (c[i].a + b[j] > c[os].a ||
        (c[i].a + b[j] == c[os].a && strcmp(c[i].name, c[os].name) < 0)) {
      c[i].a += b[j];
      i++;
      j++;
    } else
      j++;
  }
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (strcmp(c[i].name, st) == 0) return i;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d", s[i].name, &s[i].a);
  }
  scanf("%d", &m);
  b[0] = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  scanf("%s", st);
  sort(b + 1, b + m + 1);
  sort(s + 1, s + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (strcmp(s[i].name, st) == 0) {
      os = i;
      break;
    }
  }
  int a1 = findmax();
  int a2 = findmin();
  printf("%d %d\n", a1, a2);
  return 0;
}
