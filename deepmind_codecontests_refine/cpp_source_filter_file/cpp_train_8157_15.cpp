#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, u[8];
vector<pair<int, int> > v[109];
bool bo[109], boo[109];
void dfs(int q) {
  for (vector<pair<int, int> >::iterator it = v[q].begin(); it != v[q].end();
       it++) {
    if (bo[abs((*it).second)] == 1) continue;
    bo[abs((*it).second)] = 1;
    dfs(abs((*it).first));
    if ((*it).second >= 0)
      cout << (*it).second << " -" << endl;
    else
      cout << -(*it).second << " +" << endl;
  }
}
void dfs2(int q) {
  boo[q] = 1;
  for (vector<pair<int, int> >::iterator it = v[q].begin(); it != v[q].end();
       it++) {
    if (boo[(*it).first] == 1) continue;
    boo[(*it).first] = 1;
    dfs2((*it).first);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> a;
  for (b = 1; b <= a; b++) {
    cin >> c >> d;
    v[c].push_back(make_pair(d, b));
    v[d].push_back(make_pair(c, -b));
    u[c]++;
    u[d]++;
  }
  c = 0;
  d = 0;
  e = 0;
  for (b = 0; b <= 6; b++) {
    if (u[b] % 2 == 1) {
      c++;
      if (c > 2) break;
      if (c == 1)
        d = b;
      else
        e = b;
    } else {
      if (d == 0 && u[b] != 0) d = b;
    }
  }
  if (c > 2) {
    cout << "No solution";
    return 0;
  }
  dfs2(d);
  for (b = 0; b <= 6; b++) {
    if (u[b] > 0 && boo[b] == 0) {
      cout << "No solution";
      return 0;
    }
  }
  dfs(d);
  return 0;
}
