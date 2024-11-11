#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
int head[N], ver[M], Next[M];
int sta[N], ins[N], c[N];
int tot;
int dfn[N], low[N];
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
int num, cnt, top;
void tarjan(int x) {
  dfn[x] = low[x] = ++num;
  sta[++top] = x, ins[x] = 1;
  for (int i = head[x]; i; i = Next[i]) {
    if (!dfn[ver[i]]) {
      tarjan(ver[i]);
      low[x] = min(low[x], low[ver[i]]);
    } else if (ins[ver[i]]) {
      low[x] = min(low[x], dfn[ver[i]]);
    }
  }
  if (dfn[x] == low[x]) {
    cnt++;
    int y;
    do {
      y = sta[top--], ins[y] = 0;
      c[y] = cnt;
    } while (x != y);
  }
}
string name[N][2];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  string a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    name[i][0] = a.substr(0, 3);
    name[i][1] = a.substr(0, 2) + b[0];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (name[i][0] == name[j][0]) {
        add(i + n, j + n);
        add(j, i);
        add(i, j + n);
        add(j, i + n);
      }
      if (name[i][0] == name[j][1]) {
        add(i, j);
        add(j + n, i + n);
      }
      if (name[i][1] == name[j][1]) {
        add(i + n, j);
        add(j + n, i);
      }
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    if (c[i] == c[i + n]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (c[i] < c[i + n]) {
        cout << name[i][1] << endl;
      } else {
        cout << name[i][0] << endl;
      }
    }
  } else {
    cout << "NO";
  }
  return 0;
}
