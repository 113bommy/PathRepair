#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> v[MAXN];
int parent[MAXN], k, k2, a[MAXN];
void build(int x) {
  for (int i = 0; i < v[x].size(); i++) parent[v[x][i]] = v[x - 1][0];
}
void mrg(int x) {
  for (int i = 1; i < min(v[x].size(), v[x - 1].size()) and k2 > k; i++)
    parent[v[x][i]] = v[x - 1][i], k2--;
}
int main() {
  int n, t;
  cin >> n >> t >> k;
  int ind = 2;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i]; j++) v[i].push_back(ind++);
  }
  v[0].push_back(1);
  for (int i = 1; i <= t; i++) {
    build(i), k2 += a[i] - 1;
    if (i == t) k2++;
  }
  if (k2 < k) return cout << -1, 0;
  for (int i = t; i > 0; i--) mrg(i);
  if (k2 > k) return cout << -1, 0;
  cout << n << endl;
  for (int i = 2; i <= n; i++) cout << i << ' ' << parent[i] << '\n';
}
