#include <bits/stdc++.h>
using namespace std;
int n, indexx;
struct point {
  int x, y, z;
} p[500005];
struct cmpa {
  bool operator()(point a, point b) {
    if (a.x != b.x)
      return a.x > b.x;
    else if (a.y != b.y)
      return a.y > b.y;
    else
      return a.z > b.z;
  }
};
struct cmpb {
  bool operator()(point a, point b) { return a.y < b.y; }
};
int y[500005];
int readdata() {
  int ret = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  return ret;
}
void build() {
  int i;
  for (i = 1; i <= n; i++) {
    p[i].x = readdata();
    p[i].x++;
  }
  for (i = 1; i <= n; i++) {
    p[i].y = readdata();
    p[i].y++;
  }
  for (i = 1; i <= n; i++) {
    p[i].z = readdata();
    p[i].z++;
  }
  sort(p + 1, p + n + 1, cmpb());
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    if (p[i].y != p[i - 1].y)
      y[i] = ++cnt;
    else
      y[i] = cnt;
  }
  for (i = 1; i <= n; i++) {
    p[i].y = y[i];
  }
  sort(p + 1, p + n + 1, cmpa());
}
int a[500005];
void updata(int y, int z) {
  for (int pos = y; pos >= 1; pos &= pos - 1)
    if (a[pos] < z) a[pos] = z;
}
int query(int y) {
  int ans = 0;
  for (int pos = y; pos <= n; pos += pos & (-pos))
    if (ans < a[pos]) ans = a[pos];
  return ans;
}
void solve() {
  int i, j, ans = 0;
  for (i = 1; i <= n; i++) a[i] = 0;
  for (i = 1; i <= n; i = j) {
    for (j = i; j <= n && p[j].x == p[i].x; j++) {
      int y = p[j].y;
      int z = p[j].z;
      int u = query(y + 1);
      if (u >= z) ans++;
    }
    for (j = i; j <= n && p[j].x == p[i].x; j++) {
      int y = p[j].y;
      int z = p[j].z;
      updata(y, z);
    }
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    build();
    solve();
  }
}
