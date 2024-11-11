#include <bits/stdc++.h>
using namespace std;
int const bound = 1e6 + 2, N = 5e5 + 2;
long long OO = 1e18;
double eps = 1e-6;
int oo = 1e9, mod = oo + 7;
struct pip {
  int f, t, l, h, a;
};
int n;
pip v[7][7];
int state[7][7], at[7], need, mx;
bool yes = 0;
void rec(int fr, int to) {
  if (fr == n) {
    if (at[fr] != need) return;
    yes = 1;
    int cost = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (state[i][j] >= v[i][j].l && state[i][j] <= v[i][j].h) {
          cost += state[i][j] * state[i][j] + v[i][j].a * (state[i][j] > 0);
        } else
          yes = 0;
      }
    }
    if (!yes) return;
    mx = max(mx, cost);
    return;
  }
  if (to == n + 1) {
    rec(fr + 1, fr + 2);
    return;
  }
  for (int i = v[fr][to].l; i <= v[fr][to].h - state[fr][to] && i <= at[fr];
       i++) {
    at[to] += i;
    at[fr] -= i;
    state[fr][to] += i;
    rec(fr, to + 1);
    state[fr][to] -= i;
    at[to] -= i;
    at[fr] += i;
  }
}
int main() {
  cin >> n;
  for (int(i) = 0; (i) < (n * (n - 1) / 2); (i)++) {
    pip in;
    cin >> in.f >> in.t >> in.l >> in.h >> in.a;
    v[in.f][in.t] = in;
  }
  int i = 1;
  while (i <= 100) {
    memset(state, 0, sizeof state);
    memset(at, 0, sizeof at);
    at[1] = i;
    yes = 0;
    mx = 0;
    need = i;
    rec(1, 2);
    if (yes) {
      cout << i << ' ' << mx << endl;
      return 0;
    }
    i++;
  }
  cout << -1 << ' ' << -1 << endl;
  return 0;
}
