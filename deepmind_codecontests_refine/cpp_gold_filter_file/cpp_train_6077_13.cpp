#include <bits/stdc++.h>
using namespace std;
int main() {
  const int MAX = 100000;
  int n;
  scanf("%d", &n);
  vector<bool> g(MAX + 1);
  for (int i = 0; i < n; i++) {
    int gi;
    scanf("%d", &gi);
    g[gi] = true;
  }
  vector<bool> sieve(MAX + 1);
  vector<vector<int>> pf(MAX + 1);
  for (int i = 2; i <= MAX; i++)
    if (!sieve[i])
      for (int j = i; j <= MAX; j += i) sieve[j] = true, pf[j].push_back(i);
  map<int, int> pl;
  for (int i = MAX; i >= 2; i--) {
    if (!g[i]) continue;
    int cmax = 0;
    for (int f : pf[i]) cmax = max(cmax, pl[f]);
    for (int f : pf[i]) pl[f] = cmax + 1;
  }
  int vmax = 1;
  for (auto &p : pl) vmax = max(vmax, p.second);
  printf("%d", vmax);
}
