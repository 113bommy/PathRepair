#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, tmp;
int cnt[N], mx, d, che[N];
bool flag;
void bf(int n, int m) {
  memset(che, 0, sizeof(che));
  if (flag) return;
  int x, y;
  x = n - d + 1;
  y = mx - x + 2;
  if (x <= 0 || y <= 0) return;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      che[abs(i - x) + abs(j - y)]++;
      if (che[abs(i - x) + abs(j - y)] > cnt[abs(i - x) + abs(j - y)]) return;
    }
  flag = true;
  printf("%d %d\n%d %d\n", n, m, x, y);
}
int main() {
  memset(cnt, 0, sizeof(cnt));
  mx = 0;
  flag = false;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &tmp);
    cnt[tmp]++;
    mx = max(mx, tmp);
  }
  for (int i = 1; i <= mx + 1; i++)
    if (cnt[i] < i * 4) {
      d = i;
      break;
    }
  for (int i = 1; i * i <= t; i++) {
    if (t % i != 0) continue;
    if (flag) break;
    bf(i, t / i);
    bf(t / i, i);
  }
  if (!flag) puts("-1");
  return 0;
}
