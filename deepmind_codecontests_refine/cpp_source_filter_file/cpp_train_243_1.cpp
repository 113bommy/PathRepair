#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > s;
vector<int> dp, a, b;
vector<int> dd;
set<pair<int, int> > ss;
vector<int> c;
int xx;
void dfs(int child, int parent) {
  dp[child] = xx;
  int i;
  for (i = (0); i < (s[child].size()); ++i) {
    int x;
    x = s[child][i];
    if (x == parent) {
      continue;
    }
    if (dp[x] == 0) {
      dfs(x, child);
      continue;
    }
    pair<int, int> pp(min(child, x), max(child, x));
    ss.insert(pp);
  }
}
int f(int x) { return dd[x - 1] + 1; }
int main() {
  int n, i, x, y;
  cin >> n;
  dp.resize(n);
  s.resize(n);
  for (i = (0); i < (n - 1); ++i) {
    cin >> x >> y;
    x--;
    y--;
    s[x].push_back(y);
    s[y].push_back(x);
    dp[i] = 0;
  }
  dp[i] = 0;
  xx = 0;
  for (i = (0); i < (n - 1); ++i) {
    if (dp[i] != 0) {
      continue;
    }
    xx++;
    dd.push_back(i);
    dfs(i, i);
  }
  int index;
  set<pair<int, int> >::iterator it;
  for (it = ss.begin(); it != ss.end(); it++) {
    pair<int, int> p = (*it);
    a.push_back((*it).first);
    b.push_back((*it).second);
  }
  cout << a.size() << endl;
  int nnn = a.size();
  int search;
  search = 1;
  for (i = (0); i < (nnn); ++i) {
    cout << a[i] + 1 << " " << b[i] + 1 << " ";
    cout << f(search) << " " << f(search + 1) << endl;
    search++;
  }
  return 0;
}
