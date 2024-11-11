#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5) + 3;
const int MOD = 998244353;
const double PI = 4 * atan(1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
int n, m;
int a[N], b[N], c[N], d[N], k[N];
vector<int> actors[N];
vector<int> pitch[N];
set<int> s;
unordered_map<int, int> maa;
unordered_map<int, set<int> > occ;
vector<int> songs[N];
int anss[N];
void prepAns() {
  for (int i = 0; i < m; i++) {
    for (auto j : songs[i]) {
      anss[j] = i;
    }
  }
}
bool exists(int c, int j) {
  set<int>::iterator it;
  bool cond = false;
  if (s.count(c - 1) == 0) {
    cond = true;
    s.insert(c - 1);
  }
  it = s.find(c - 1);
  it++;
  if (it == s.end()) {
    if (cond) {
      s.erase(c - 1);
    }
    return 0;
  }
  int x = *it;
  int y = *occ[x].begin();
  songs[j].push_back(y);
  occ[x].erase(occ[x].begin());
  if (occ[x].size() == 0) {
    s.erase(x);
  }
  if (cond) {
    s.erase(c - 1);
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    s.insert(a[i]);
    s.insert(b[i]);
  }
  cin >> m;
  s.insert(0);
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i] >> k[i];
    s.insert(c[i]);
    s.insert(d[i]);
  }
  int ind = 1;
  for (auto t : s) {
    maa[t] = ind++;
  }
  for (int i = 0; i < n; i++) {
    a[i] = maa[a[i]];
    b[i] = maa[b[i]];
    pitch[b[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    c[i] = maa[c[i]];
    d[i] = maa[d[i]];
    actors[d[i]].push_back(i);
  }
  maa.clear();
  s.clear();
  int ans = 0;
  for (int i = 1; i < ind; i++) {
    for (auto j : pitch[i]) {
      s.insert(b[j]);
      occ[b[j]].insert(j);
    }
    for (auto j : actors[i]) {
      while (k[j] && exists(c[j], j)) {
        k[j]--;
        ans++;
      }
    }
  }
  if (ans == n) {
    cout << "YES\n";
    prepAns();
    for (int i = 0; i < n; i++) {
      cout << anss[i] + 1 << " ";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
