#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, l, x, b[212121], kol;
int u[212121];
struct po {
  int x, y;
} a[212121];
bool cmp(po a, po b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
long long ans, m;
int main() {
  cin >> n;
  for (i = 1; i <= n + n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = (i % n);
    if (a[i].y == 0) a[i].y = n;
  }
  cin >> m;
  sort(a + 1, a + n + n + 1, &cmp);
  ans = 1;
  for (i = 1; i <= n + n; i++) {
    if (i == 1 || a[i].x != a[i - 1].x) {
      k = 1;
      kol++;
    } else {
      k++;
      x = k;
      j = 2;
      while (j * j <= x) {
        if (x % j == 0) {
          while (x % j == 0) {
            b[j]++;
            x /= j;
          }
        }
        j++;
      }
      if (x > 1) b[x]++;
      if (a[i].y == a[i - 1].y) b[2]--;
    }
  }
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= b[i]; j++) {
      ans = (ans * i) % m;
    }
  }
  cout << ans;
  return 0;
}
