#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;
long n, m, i, j, v1, v2;
vector<vector<pair<long long, long long>>> reb;
vector<long long> col, tc;
bool viv = false;
long long will() {
  set<pair<long long, pair<long long, long long>>> can;
  for (auto p : reb[v1]) can.insert({p.second, {v1, p.first}});
  vector<long long> hard(n, -1);
  while (can.size()) {
    auto z = *can.begin();
    long long add = z.second.second;
    long long was = z.second.first;
    long long nw = z.first;
    hard[add] = max(hard[was], nw);
    for (auto pr : reb[add]) {
      if (can.find({pr.second, {pr.first, add}}) != can.end())
        can.erase({pr.second, {pr.first, add}});
      else
        can.insert({pr.second, {add, pr.first}});
    }
  }
  if (viv) {
    for (auto i : hard) cout << i << ' ';
    cout << endl;
  }
  long long kol = 0;
  for (auto i : hard)
    if (i == -1) kol++;
  if (kol > 1) return mod - 7;
  return hard[v2];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  reb.resize(n);
  for (i = 0; i < m; i++) {
    long a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (i) {
      reb[a].push_back({b, c});
      reb[b].push_back({a, c});
    } else
      v1 = a, v2 = b;
  }
  col.assign(n, -1);
  tc.assign(n, -1);
  cout << will();
  return 0;
}
