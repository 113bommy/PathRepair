#include <bits/stdc++.h>
using namespace std;
void reloc() {
  freopen("/Users/admin/Desktop/cards.in", "r", stdin);
  freopen("/Users/admin/Desktop/cards.out", "w", stdout);
  return;
}
const int n = 8;
const long long inf = 1ll << 62;
bool ok = 0;
int v[n + 1];
struct point {
  int a[4];
  point operator-(const point b) const {
    point ans;
    ans.a[1] = a[1] - b.a[1];
    ans.a[2] = a[2] - b.a[2];
    ans.a[3] = a[3] - b.a[3];
    return ans;
  }
  long long operator*(const point b) const {
    return 1ll * a[1] * b.a[1] + 1ll * a[2] * b.a[2] + 1ll * a[3] * b.a[3];
  }
} p[n + 1], c[n + 1];
inline long long dist(point a, point b) {
  long long ans = 0;
  for (int i = 1; i <= 3; i++) {
    ans += (a.a[i] - b.a[i]) * (a.a[i] - b.a[i]);
  }
  return ans;
}
void read() {
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d\n", &p[i].a[1], &p[i].a[2], &p[i].a[3]);
  }
  return;
}
void check() {
  point k[10];
  int tt;
  long long mini;
  for (int i = 1; i <= n; i++) {
    tt = 0;
    mini = inf;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        long long d = dist(c[i], c[j]);
        if (d == mini) {
          tt++;
          k[tt] = c[j];
        } else if (d < mini) {
          tt = 1;
          k[tt] = c[j];
          mini = d;
        }
      }
    }
    if (tt != 3 || mini == 0) return;
    for (int j = 2; j <= tt; j++) {
      if ((k[1] - c[i]) * (k[j] - c[i]) != 0) return;
    }
    if ((k[2] - c[i]) * (k[3] - c[i]) != 0) return;
  }
  ok = 1;
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2; j++) {
      printf("%d ", c[i].a[j]);
    }
    printf("%d\n", c[i].a[3]);
  }
  return;
}
void dfs(int c1, int c2) {
  if (c1 == 8) {
    check();
  } else {
    for (int i = 1; i <= 3; i++) {
      if ((v[c1 + 1] & (1 << (i - 1))) == 0) {
        v[c1 + 1] |= (1 << (i - 1));
        c[c1 + 1].a[c2 + 1] = p[c1 + 1].a[i];
        if (c2 == 2)
          dfs(c1 + 1, 0);
        else
          dfs(c1, c2 + 1);
        v[c1 + 1] ^= (1 << (i - 1));
        if (ok) return;
      }
    }
  }
  return;
}
void work() {
  memset(v, 0, sizeof(v));
  dfs(0, 0);
  if (ok) return;
  printf("NO\n");
  return;
}
int main() {
  read();
  work();
  return 0;
}
