#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 50;
int n, x, y;
int b[N];
set<int> ocu[N];
int res[N];
int getnxt(int v) {
  if (ocu[v].empty()) return -1;
  int c = *ocu[v].begin();
  ocu[v].erase(ocu[v].begin());
  return c;
}
void solve() {
  cin >> n >> x >> y;
  for (int i = 0; i < (n + 2); ++i) {
    ocu[i].clear();
  }
  int rem = n;
  priority_queue<pair<int, int> > pque;
  map<int, int> mp;
  for (int i = 0; i < (n); ++i) {
    cin >> b[i];
    mp[b[i]]++;
    ocu[b[i]].insert(i);
  }
  int mex = 1;
  for (auto &p : mp) {
    if (p.first == mex) mex++;
  }
  fill(res, res + n, mex);
  for (auto &p : mp) pque.push({p.second, p.first});
  while (x > 0) {
    pair<int, int> p = pque.top();
    pque.pop();
    res[getnxt(p.second)] = p.second;
    p.first--;
    if (p.first) pque.push(p);
    x--, y--;
    rem--;
  }
  int mxcnt = (pque.empty() ? 0 : pque.top().first);
  if (2 * (rem - mxcnt) < y) {
    cout << "NO\n";
    return;
  }
  while (y > 0) {
    if (y == 3 && pque.size() == 3 && pque.top().first == 1) {
      int a = pque.top().second;
      pque.pop();
      int b = pque.top().second;
      pque.pop();
      int c = pque.top().second;
      pque.pop();
      res[getnxt(a)] = c;
      res[getnxt(b)] = a;
      res[getnxt(c)] = b;
      break;
    }
    pair<int, int> p = pque.top();
    pque.pop();
    pair<int, int> p2 = pque.top();
    pque.pop();
    res[getnxt(p.second)] = p2.second;
    p.first--;
    if (p.first) pque.push(p);
    y--;
    if (y) {
      res[getnxt(p2.second)] = p.second;
      p2.first--;
      if (p2.first) pque.push(p2);
      y--;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < (n); ++i) cout << res[i] << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
