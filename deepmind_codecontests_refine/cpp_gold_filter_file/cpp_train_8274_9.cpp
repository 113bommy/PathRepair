#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 2e4 + 5;
int n, m, p, id[N][N], f[M], a[N][N], num[M];
bool co[N][N];
char s[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int mo(int x) { return x >= p ? x - p : x; }
struct A {
  int x, y;
};
vector<A> V;
int ksm(long long a, int b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p, b >>= 1;
  }
  return ret;
}
int det(int n) {
  int ret = 1;
  for (int i = 1; i < n; i++) {
    if (!a[i][i]) {
      for (int j = i + 1; j < n; j++) {
        if (a[j][i]) {
          for (int k = i; k < n; k++) {
            swap(a[i][k], a[j][k]);
          }
          ret = -ret;
          break;
        }
      }
    }
    int t = ksm(a[i][i], p - 2);
    for (int j = i + 1; j < n; j++) {
      if (a[j][i]) {
        int tt = (long long)a[j][i] * t % p;
        for (int k = i; k < n; k++) {
          a[j][k] = mo((a[j][k] - (long long)a[i][k] * tt) % p + p);
        }
      }
    }
  }
  for (int i = 1; i < n; i++) ret = (long long)ret * a[i][i] % p;
  return mo(ret + p);
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  int cnt = 0;
  int ans = 0, Num = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      id[i][j] = ++cnt;
      if (i != 1)
        co[i][j] = !co[i - 1][j];
      else
        co[i][j] = !co[i][j - 1];
      f[cnt] = cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) {
      if (s[j] == '/') {
        int u = find(id[i][j + 1]), v = find(id[i + 1][j]);
        if (u != v) {
          f[u] = v;
        }
      } else if (s[j] == '*') {
        V.push_back((A){i, j});
      } else {
        int u = find(id[i][j]), v = find(id[i + 1][j + 1]);
        if (u != v) {
          f[u] = v;
        }
      }
    }
  }
  cnt = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      if (!co[i][j]) {
        int u = find(id[i][j]);
        if (u != id[i][j]) {
          if (!num[u]) num[u] = ++cnt;
        }
      }
    }
  }
  for (A i : V) {
    if (!co[i.x][i.y]) {
      int u = find(id[i.x][i.y]), v = find(id[i.x + 1][i.y + 1]);
      if (u != v) {
        if (!num[u]) num[u] = ++cnt;
        if (!num[v]) num[v] = ++cnt;
        a[num[u]][num[u]] = mo(a[num[u]][num[u]] + 1),
        a[num[v]][num[v]] = mo(a[num[v]][num[v]] + 1);
        a[num[u]][num[v]] = mo(a[num[u]][num[v]] + p - 1),
        a[num[v]][num[u]] = mo(a[num[v]][num[u]] + p - 1);
      }
    } else {
      int u = find(id[i.x][i.y + 1]), v = find(id[i.x + 1][i.y]);
      if (u != v) {
        if (!num[u]) num[u] = ++cnt;
        if (!num[v]) num[v] = ++cnt;
        a[num[u]][num[u]] = mo(a[num[u]][num[u]] + 1),
        a[num[v]][num[v]] = mo(a[num[v]][num[v]] + 1);
        a[num[u]][num[v]] = mo(a[num[u]][num[v]] + p - 1),
        a[num[v]][num[u]] = mo(a[num[v]][num[u]] + p - 1);
      }
    }
  }
  bool fl = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      if (!co[i][j] && !num[find(id[i][j])]) {
        fl = 1;
        break;
      }
    }
    if (fl) break;
  }
  if (!fl) ans = mo(ans + det(cnt)), Num += 2;
  memset(num, 0, sizeof(num));
  memset(a, 0, sizeof(a));
  cnt = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      if (co[i][j]) {
        int u = find(id[i][j]);
        if (u != id[i][j]) {
          if (!num[u]) num[u] = ++cnt;
        }
      }
    }
  }
  for (A i : V) {
    if (co[i.x][i.y]) {
      int u = find(id[i.x][i.y]), v = find(id[i.x + 1][i.y + 1]);
      if (u != v) {
        if (!num[u]) num[u] = ++cnt;
        if (!num[v]) num[v] = ++cnt;
        a[num[u]][num[u]] = mo(a[num[u]][num[u]] + 1),
        a[num[v]][num[v]] = mo(a[num[v]][num[v]] + 1);
        a[num[u]][num[v]] = mo(a[num[u]][num[v]] + p - 1),
        a[num[v]][num[u]] = mo(a[num[v]][num[u]] + p - 1);
      }
    } else {
      int u = find(id[i.x][i.y + 1]), v = find(id[i.x + 1][i.y]);
      if (u != v) {
        if (!num[u]) num[u] = ++cnt;
        if (!num[v]) num[v] = ++cnt;
        a[num[u]][num[u]] = mo(a[num[u]][num[u]] + 1),
        a[num[v]][num[v]] = mo(a[num[v]][num[v]] + 1);
        a[num[u]][num[v]] = mo(a[num[u]][num[v]] + p - 1),
        a[num[v]][num[u]] = mo(a[num[v]][num[u]] + p - 1);
      }
    }
  }
  fl = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      if (co[i][j] && !num[find(id[i][j])]) {
        fl = 1;
        break;
      }
    }
    if (fl) break;
  }
  if (!fl) {
    ans = mo(ans + det(cnt));
    Num++;
  }
  printf("%d\n", ans);
  return 0;
}
