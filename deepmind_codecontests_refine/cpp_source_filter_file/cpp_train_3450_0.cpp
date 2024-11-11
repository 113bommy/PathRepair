#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
vector<int> v[maxn];
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = i, v[i].push_back(i);
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    if (v[a[x]].size() < v[a[y]].size()) swap(x, y);
    int ss = a[x], sqr = a[y];
    for (int j = 0; j < v[sqr].size(); j++) {
      v[ss].push_back(v[sqr][j]);
      a[v[sqr][j]] = ss;
    }
    v[sqr].clear();
  }
  for (int i = 0; i < n - 1; i++) cout << v[a[1]][i] << ' ';
  return 0;
}
