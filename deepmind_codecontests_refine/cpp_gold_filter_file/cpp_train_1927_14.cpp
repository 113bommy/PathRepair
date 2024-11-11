#include <bits/stdc++.h>
using namespace std;
int n, k, tot, head[210];
long long Ans, f[210][210];
struct Edge {
  int next, now, con;
} lim[410];
inline void make(int from, int to, int v) {
  lim[++tot].next = head[from];
  head[from] = tot;
  lim[tot].now = to;
  lim[tot].con = v;
}
bool Check(int Midl, int Midr, int Nowl, int Nowr) {
  for (int i = head[Nowl]; i; i = lim[i].next) {
    int Nex = lim[i].now, Nec = lim[i].con;
    if (Nex == Nowr) {
      if (Nec == 4 || Nec == 2) return 0;
    } else if (Nec == 1 || Nec == 4) {
      if (Nex > Midl && Nex < Midr) return 0;
    } else if (Nec == 2 || Nec == 5) {
      if (Nex < Midl || Nex > Midr) return 0;
    } else if (Nec == 3)
      return 0;
  }
  for (int i = head[Nowr]; i; i = lim[i].next) {
    int Nex = lim[i].now, Nec = lim[i].con;
    if (Nex == Nowl) {
      if (Nec == 4 || Nec == 2) return 0;
    } else if (Nec == 1 || Nec == 4) {
      if (Nex > Midl && Nex < Midr) return 0;
    } else if (Nec == 2 || Nec == 5) {
      if (Nex < Midl || Nex > Midr) return 0;
    } else if (Nec == 3)
      return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, x, y, z; i <= k; ++i) {
    string cmd;
    cin >> x >> cmd >> y;
    if (cmd[0] == '>') {
      if (cmd[1] == '=')
        z = 1;
      else
        z = 4;
    } else if (cmd[0] == '<') {
      if (cmd[1] == '=')
        z = 5;
      else
        z = 2;
    } else
      z = 3;
    if (x == y) {
      if (z == 4 || z == 2) {
        cout << 0 << endl;
        return 0;
      } else
        continue;
    }
    make(x, y, z);
    make(y, x, 6 - z);
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= i * 2; ++j) {
      if (i * 2 - j >= 2 &&
          (k == 0 || Check(i * 2 - j, 2 * n - j + 1, i * 2 - j - 1, i * 2 - j)))
        f[i * 2 - j][j] += f[i * 2 - j - 2][j];
      if (j >= 2 && (k == 0 || Check(i * 2 - j, 2 * n - j + 1, 2 * n - j + 1,
                                     2 * n - j + 2)))
        f[i * 2 - j][j] += f[i * 2 - j][j - 2];
      if (j >= 1 && i * 2 - j >= 1 &&
          (k == 0 || Check(i * 2 - j, 2 * n - j + 1, i * 2 - j, 2 * n - j + 1)))
        f[i * 2 - j][j] += f[i * 2 - j - 1][j - 1];
    }
  for (int i = 0; i <= 2 * n; ++i) Ans += f[i][2 * n - i];
  printf("%lld\n", Ans / 3);
  return 0;
}
