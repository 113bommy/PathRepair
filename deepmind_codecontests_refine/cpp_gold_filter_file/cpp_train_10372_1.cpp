#include <bits/stdc++.h>
using namespace std;
vector<int> ad[100004];
int parent[100004];
long long si[100004];
int vis[100004] = {0};
vector<long long> m;
int _find(int a) {
  if (parent[a] == a) return a;
  parent[a] = _find(parent[a]);
  return parent[a];
}
void _union(int a, int b) {
  a = _find(a);
  b = _find(b);
  if (a != b) {
    si[a] = si[a] + si[b];
    parent[b] = a;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    si[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int el;
    cin >> el;
    _union(i, el);
  }
  for (int i = 1; i <= n; i++) {
    int p = _find(parent[i]);
    if (vis[p] == 0) {
      m.push_back(si[p]);
      vis[p] = 1;
    }
  }
  sort(m.begin(), m.end(), greater<int>());
  long long ans = 0;
  if (m.size() > 1) {
    ans += (m[0] + m[1]) * (m[0] + m[1]);
    for (int i = 2; i < m.size(); i++) ans += m[i] * m[i];
  } else
    ans += m[0] * m[0];
  cout << ans << "\n";
  return 0;
}
