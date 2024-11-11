#include <bits/stdc++.h>
using namespace std;
const int xt[4] = {1, 1, -1, -1};
const int yt[4] = {1, -1, -1, 1};
struct rec {
  int x, y, k;
} v;
int n, m, ans, p1[110000], p2[110000], p3[110000], p4[110000];
long long sum = 0;
int f1() {
  char str[5];
  scanf("%s", str);
  if (str[0] == 'D' && str[1] == 'L') return 1;
  if (str[0] == 'D' && str[1] == 'R') return 0;
  if (str[0] == 'U' && str[1] == 'L') return 3;
  return 2;
}
rec change(rec v) {
  if (v.k == 0) {
    int t = min(n - v.x, m - v.y);
    v.x += t, v.y += t;
    sum += t;
    return v;
  }
  if (v.k == 1) {
    int t = min(n - v.x, v.y - 1);
    v.x += t;
    v.y -= t;
    sum += t;
    return v;
  }
  if (v.k == 2) {
    int t = min(v.x - 1, v.y - 1);
    v.x -= t;
    v.y -= t;
    sum += t;
    return v;
  }
  int t = min(v.x - 1, m - v.y);
  v.x -= t;
  v.y += t;
  sum += t;
  return v;
}
bool work(rec &v) {
  if (v.x == 1) {
    p1[v.y]++;
    if (p1[v.y] == 1) ans--;
    v.k = 3 - v.k;
    if (p1[v.y] > 3) return 1;
  }
  if (v.x == n) {
    p2[v.y]++;
    if (p2[v.y] == 1) ans--;
    v.k = 3 - v.k;
    if (p2[v.y] > 3) return 1;
  }
  if (v.y == 1) {
    p3[v.x]++;
    if (p3[v.x] == 1) ans--;
    v.k ^= 1;
    if (p3[v.x] > 3) return 1;
  }
  if (v.y == m) {
    p4[v.x]++;
    if (p4[v.x] == 1) ans--;
    v.k ^= 1;
    if (p4[v.x] > 3) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &v.x, &v.y);
  v.k = f1();
  if (v.x == 1 && v.y == 1) v.k = 0;
  if (v.x == n && v.y == 1) v.k = 3;
  if (v.x == 1 && v.y == m) v.k = 1;
  if (v.x == n && v.y == m) v.k = 2;
  for (int i = 1; i <= m; i++) {
    if ((v.x + v.y) % 2 == (1 + i) % 2) ans++;
    if ((v.x + v.y) % 2 == (n + i) % 2) ans++;
  }
  for (int i = 1; i <= n; i++) {
    if ((v.x + v.y) % 2 == (1 + i) % 2) ans++;
    if ((v.x + v.y) % 2 == (m + i) % 2) ans++;
  }
  if (v.x == 1) p1[v.y]++, ans--;
  if (v.x == n) p2[v.y]++, ans--;
  if (v.y == 1) p3[v.x]++, ans--;
  if (v.y == m) p4[v.x]++, ans--;
  while (1) {
    v = change(v);
    if (work(v)) break;
    if (!ans) {
      cout << sum + 1 << endl;
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
