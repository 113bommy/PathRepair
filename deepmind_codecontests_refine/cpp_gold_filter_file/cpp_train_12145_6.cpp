#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int maxn = 500000 + 7;
const int maxp = 107;
int n, k, p;
int Data[maxn];
int room[maxp][maxn];
int least[maxp];
void update(int *room, int x, int value) {
  x++;
  while (x <= p) {
    room[x] = min(room[x], value);
    x += x & -x;
  }
}
int query(int *room, int x) {
  x++;
  int rt = inf;
  while (x) {
    rt = min(rt, room[x]);
    x -= x & -x;
  }
  return rt;
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &Data[i]);
  for (int i = 1; i <= n; i++) Data[i] = (Data[i - 1] + Data[i]) % p;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= p; j++) {
      room[i][j] = inf;
    }
  for (int i = 0; i <= k; i++) least[i] = inf;
  update(room[0], 0, 0);
  least[0] = min(least[0], 0);
  for (int i = 1; i < n; i++) {
    for (int j = k - 1; j >= 0; j--) {
      int u = query(room[j], Data[i]);
      if (u != inf) {
        update(room[j + 1], Data[i], u);
        least[j + 1] = min(least[j + 1], u);
      }
      u = least[j];
      if (u != inf) {
        update(room[j + 1], Data[i], u + 1);
        least[j + 1] = min(least[j + 1], u + 1);
      }
    }
  }
  int ans = inf;
  int u = query(room[k - 1], Data[n]);
  if (u != inf) {
    ans = min(ans, u * p + Data[n]);
  }
  u = least[k - 1];
  if (u != inf) {
    ans = min(ans, u * p + p + Data[n]);
  }
  printf("%d\n", ans);
  return 0;
}
