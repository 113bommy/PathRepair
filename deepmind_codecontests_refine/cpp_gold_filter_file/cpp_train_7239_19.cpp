#include <bits/stdc++.h>
using namespace std;
inline int cmp(double a, double b = 0.0) {
  if (fabs(a - b) <= (1e-9)) return 0;
  if (a < b) return -1;
  return 1;
}
int n;
int minf[7][7], maxf[7][7], cost[7][7];
vector<int> sol;
int fs, cs;
map<vector<int>, int> m;
int solve() {
  if (sol[0] == n - 1) return 0;
  if (m.count(sol)) return m[sol];
  int &r = m[sol];
  r = -0x3f3f3f3f;
  int v = sol[0];
  int u = sol[1];
  if (u == n) {
    if (sol[v + 2] > 0) return r = -0x3f3f3f3f;
    sol[0] = v + 1;
    sol[1] = v + 2;
    r = solve();
    sol[0] = v;
    sol[1] = n;
    return r;
  }
  if (sol[v + 2] < minf[v][u]) return r = -0x3f3f3f3f;
  for (int i = minf[v][u]; i <= min(sol[v + 2], maxf[v][u]); i++) {
    int c = i * i;
    if (i > 0) c += cost[v][u];
    sol[v + 2] -= i;
    sol[1]++;
    sol[u + 2] += i;
    int rs = solve();
    if (rs > -0x3f3f3f3f) r = max(r, rs + c);
    sol[1]--;
    sol[u + 2] -= i;
    sol[v + 2] += i;
  }
  return r;
}
int main() {
  fs = 100;
  cs = 0;
  sol = vector<int>(8);
  cin >> n;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    int s, f, l, h, a;
    cin >> s >> f >> l >> h >> a;
    s--;
    f--;
    minf[s][f] = l;
    maxf[s][f] = h;
    cost[s][f] = a;
  }
  for (int i = 0; i <= 25; i++) {
    sol[1] = 1;
    sol[2] = i;
    m.clear();
    int r = solve();
    if (r >= 0) {
      cout << i << " " << r << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
