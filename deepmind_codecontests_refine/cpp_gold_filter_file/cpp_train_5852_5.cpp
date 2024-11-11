#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> v;
vector<bool> vi;
vector<long long int> p, ne;
map<long long int, long long int> m;
void dfs(long long int r) {
  if (vi[r]) return;
  vi[r] = true;
  if (m[r]) {
    if (m[r] > 0)
      p.push_back(r);
    else
      ne.push_back(r);
  }
  for (auto it : v[r]) dfs(it);
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, x, y, z, mt, n;
  cin >> n >> mt;
  vi.resize(n, false);
  v.resize(n);
  while (mt--) {
    cin >> x >> y >> z;
    m[x - 1] -= z;
    m[y - 1] += z;
    v[x - 1].push_back(y - 1);
    v[y - 1].push_back(x - 1);
  }
  vector<pair<pair<long long int, long long int>, long long int>> vr;
  for (i = 0; i < n; i++) {
    if (!vi[i]) {
      p.clear();
      ne.clear();
      dfs(i);
      j = k = 0;
      x = p.size();
      y = ne.size();
      while (j < x && k < y) {
        if (abs(m[p[j]]) < abs(m[ne[k]])) {
          vr.push_back({{ne[k], p[j]}, abs(m[p[j]])});
          m[ne[k]] += m[p[j++]];
        } else if (abs(m[p[j]]) > abs(m[ne[k]])) {
          vr.push_back({{ne[k], p[j]}, abs(m[ne[k]])});
          m[p[j]] += m[ne[k++]];
        } else {
          vr.push_back({{ne[k], p[j]}, abs(m[p[j]])});
          j++;
          k++;
        }
      }
    }
  }
  cout << vr.size() << '\n';
  for (auto it : vr)
    cout << it.first.first + 1 << " " << it.first.second + 1 << " " << it.second
         << '\n';
  return 0;
}
