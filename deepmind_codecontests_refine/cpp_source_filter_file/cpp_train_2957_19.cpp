#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const int M = 1e9 + 9;
const int N = 111111;
const double eps = 1e-6;
int n, m, p[N], x, y;
vector<int> g[N];
bool ok;
bool check(int a, int b) {
  for (int i = 0; i < g[a].size(); i++)
    if (b == g[a][i]) return true;
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    scanf("%d %d", &x, &y), g[x].push_back(y), g[y].push_back(x);
  for (int i = 0; i < n; i++) p[i] = i + 1;
  random_shuffle(p, p + n);
  p[n] = p[0];
  while (clock() < 2500) {
    ok = true;
    for (int i = 0; i < m; i++)
      if (check(p[i], p[i + 1])) {
        ok = false;
        swap(p[i], p[rand() % n]);
        p[n] = p[0];
      }
    if (ok) break;
  }
  if (ok)
    for (int i = 1; i <= m; i++) printf("%d %d\n", p[i], p[i + 1]);
  else
    puts("-1");
  return 0;
}
