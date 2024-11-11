#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, x, y, m, z;
vector<int> v[N];
vector<pair<int, int> > ve[N];
long long fp[N], ej, sd[N];
void sgd(int dg, int op, int sg) {
  for (int i = 0; i < ve[dg].size(); ++i) {
    ej += ve[dg][i].second;
    sd[min(sg + ve[dg][i].first + 1, N - 1)] -= ve[dg][i].second;
  }
  ej += sd[sg];
  fp[dg] = ej;
  for (int i = 0; i < v[dg].size(); ++i) {
    if (v[dg][i] != op) {
      sgd(v[dg][i], dg, sg + 1);
    }
  }
  for (int i = 0; i < ve[dg].size(); ++i) {
    ej -= ve[dg][i].second;
    sd[min(sg + ve[dg][i].first + 1, N - 1)] += ve[dg][i].second;
  }
  ej -= sd[sg];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    ve[x].push_back({y, z});
  }
  sgd(1, 0, 1);
  for (int i = 1; i <= n; ++i) {
    cout << fp[i] << " ";
  }
  cout << endl;
  return 0;
}
