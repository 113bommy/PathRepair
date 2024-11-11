#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 77;
bool o[N];
int kolor[N];
vector<int> G[N];
void dfs(int v, int kol) {
  o[v] = 1;
  kolor[v] = kol;
  for (int w : G[v]) {
    if (o[w]) continue;
    dfs(w, kol ^ 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > pairs;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    pairs.push_back({a, b});
  }
  for (int i = 1; i <= n; i++) {
    int pie = 2 * i;
    int dru = 2 * i + 1;
    if (dru > 2 * n) dru = 1;
    G[pie].push_back(dru);
    G[dru].push_back(pie);
  }
  for (int i = 1; i <= 2 * n; i++)
    if (!o[i]) dfs(i, 0);
  for (auto p : pairs) {
    cout << kolor[p.first] + 1 << " " << kolor[p.second] + 1 << "\n";
  }
}
