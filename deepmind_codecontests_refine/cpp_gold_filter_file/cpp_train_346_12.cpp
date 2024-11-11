#include <bits/stdc++.h>
using namespace std;
template <class T>
bool up_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool up_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
int n;
int a[100020];
int Z[7][20] = {
    {},
    {},
    {2, 1, 2},
    {4, 1, 2, 3, 2},
    {6, 1, 2, 3, 4, 3, 2},
    {8, 1, 2, 3, 4, 5, 4, 3, 2},
    {10, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2},
};
int cnt;
int pos[8][20];
long long c[32][100020];
void modify(long long* T, int x, long long delta) {
  while (x <= n) T[x] += delta, x += (x & (-x));
}
long long getsum(long long* T, long long x) {
  long long sum = 0;
  while (x) sum += T[x], x -= (x & (-x));
  return sum;
}
int trans(int i, int g) {
  int t = i % g;
  return t == 0 ? g : t;
}
void Init() {
  memset(c, 0, sizeof(c));
  ;
  cnt = 0;
  for (int z = 2; z <= 6; ++z) {
    for (int i = 1; i <= Z[z][0]; ++i) {
      pos[z][i] = ++cnt;
      for (int j = 1; j <= n; ++j) {
        int t = (trans(j, Z[z][0]) + i - 1) % Z[z][0];
        if (t == 0) t = Z[z][0];
        modify(c[cnt], j, (long long)a[j] * Z[z][t]);
      }
    }
  }
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    Init();
    int m;
    cin >> m;
    while (m--) {
      int op, x, y, z;
      scanf("%d", &op);
      if (1 == op) {
        scanf("%d%d", &x, &y);
        if (a[x] == y) continue;
        int delta = a[x];
        for (int z = 2; z <= 6; ++z) {
          for (int i = 1; i <= Z[z][0]; ++i) {
            int g = pos[z][i];
            int t = (trans(x, Z[z][0]) + i - 1) % Z[z][0];
            if (t == 0) t = Z[z][0];
            modify(c[g], x, -(long long)delta * Z[z][t]);
            modify(c[g], x, (long long)y * Z[z][t]);
          }
        }
        a[x] = y;
      } else {
        scanf("%d%d%d", &x, &y, &z);
        int t;
        for (int i = 1; i <= Z[z][0]; ++i) {
          int f = (trans(x, Z[z][0]) + i - 1) % Z[z][0];
          if (f == 0) f = Z[z][0];
          if (1 == f) {
            t = i;
            break;
          }
        }
        t = pos[z][t];
        long long ans = getsum(c[t], y);
        ans -= getsum(c[t], x - 1);
        cout << ans << endl;
      }
    }
  }
}
