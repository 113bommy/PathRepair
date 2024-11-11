#include <bits/stdc++.h>
using namespace std;
int c[100001];
vector<set<int> > v;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  v.resize(100001);
  for (int i = 1; i <= n; i++) cin >> c[i];
  while (m--) {
    cin >> a >> b;
    if (c[a] != c[b]) {
      v[c[a]].insert(c[b]);
      v[c[b]].insert(c[a]);
    }
  }
  long long mx = 0, cl = 0;
  for (int i = 1; i < v.size(); i++) {
    if (mx < (long long)v[i].size()) {
      mx = (long long)v[i].size();
      cl = i;
    }
  }
  if (mx)
    cout << cl;
  else
    cout << *min_element(c, c + n + 1);
  return 0;
}
