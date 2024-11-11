#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long mod = 1000000007;
int tablica[2];
long long potega(long long base, long long pot) {
  if (pot == 0) return 1;
  if (pot == 1) return base;
  if (pot % 2 == 0) {
    long long res = potega(base, pot / 2);
    return ((res * res) % mod);
  } else
    return ((potega(base, pot - 1) * base) % mod);
}
int bs(int pocz, int kon, int szu) {
  int sr;
  while (pocz < kon) {
    sr = (pocz + kon) / 2;
    if (tablica[sr] >= szu)
      kon = sr;
    else
      pocz = sr + 1;
  }
  return pocz;
}
int n, m, x, y, ile[100007], w[100007], odw[100007];
vector<pair<int, int> > v[100007];
vector<int> odp;
queue<int> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back({y, i});
    v[y].push_back({x, i});
    ile[x]++;
    ile[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (ile[i] <= w[i]) q.push(i);
  }
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < v[x].size(); i++) {
      y = v[x][i].first;
      int el = v[x][i].second;
      if (odw[el] == 1) continue;
      odw[el] = 1;
      odp.push_back(el);
      ile[y]--;
      if (ile[y] == w[y]) q.push(y);
    }
  }
  if (odp.size() < m) {
    printf("DEAD\n");
    return 0;
  }
  reverse(odp.begin(), odp.end());
  printf("ALIVE\n");
  for (int i = 0; i < odp.size(); i++) printf("%d ", odp[i]);
  return 0;
}
