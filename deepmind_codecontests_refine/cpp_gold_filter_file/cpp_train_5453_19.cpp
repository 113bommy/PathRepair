#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 123;
const long long INF = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
const int MOD = (int)1e9 + 7;
void megaRandom() {
  unsigned int FOR;
  asm("rdtsc" : "=A"(FOR));
  srand(FOR);
}
int n;
vector<int> g[N];
long double res;
void dfs(int x, int pr = 0, int h = 1) {
  if (h > 0) res += (1.0 / h);
  for (auto to : g[x]) {
    if (to == pr) continue;
    dfs(to, x, h + 1);
  }
}
int main() {
  megaRandom();
  cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs(1);
  cout << fixed << setprecision(6) << res;
  return 0;
}
