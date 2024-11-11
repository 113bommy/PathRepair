#include <bits/stdc++.h>
using namespace std;
int n, d, k, id = 0;
vector<pair<int, int> > v;
void dfs(int deep, int anc) {
  if (deep <= 0 || id > n) return;
  id++;
  int cur = id;
  v.push_back(make_pair(anc, cur));
  if (id >= n || deep <= 1) return;
  for (int i = 1; i < k; i++) {
    if (id >= n) return;
    dfs(deep - 1, cur);
  }
}
int main() {
  v.reserve(100000);
  cin >> n >> d >> k;
  d++;
  if ((k == 1 && n > 2) || d > n) {
    cout << "NO";
    return 0;
  }
  id = d;
  for (int i = 0; i < d; i++) {
    if (i > 0) v.push_back(make_pair(i, i + 1));
    for (int j = 1 + ((i == 0 || i == n - 1) ? 0 : 1); j < k; j++) {
      if (id >= n) break;
      dfs(min(i, d - i - 1), i + 1);
    }
  }
  if (id < n) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
  return 0;
}
