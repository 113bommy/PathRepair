#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long inf18 = 1e18 + 7;
const int N = 3e5 + 7;
int a[N];
vector<pair<long long, int> > can[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> v[50];
  int err[50];
  for (int j = 0; j < 20; ++j) err[j] = (1 << j);
  vector<pair<long long, int> > bit[50];
  int d[30];
  for (int i = n - 1; i >= 0; --i) {
    set<int> s;
    for (int j = 0; j < 19; ++j) d[j] = 1000000;
    for (int j = 0; j < 19; ++j)
      if (err[j] & a[i]) {
        d[j] = i;
        s.insert(j);
        for (auto k : bit[j]) {
          d[k.first] = min(d[k.first], k.second);
          s.insert(k.first);
        }
      }
    vector<pair<long long, int> > vv;
    for (auto j : s) {
      can[i].push_back({j, d[j]});
      vv.push_back({j, d[j]});
    }
    for (int j = 0; j < 19; ++j)
      if (err[j] & a[i]) {
        bit[j] = vv;
      }
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    bool er = 0;
    for (auto i : can[x])
      if (err[i.first] & y && i.second <= y) {
        er = 1;
        break;
      }
    if (er)
      cout << "Shi\n";
    else
      cout << "Fou\n";
  }
}
