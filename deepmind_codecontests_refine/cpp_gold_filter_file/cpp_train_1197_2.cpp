#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
pair<int, int> ans[maxn];
int w[maxn];
map<int, set<pair<int, int> > > Sval;
vector<int> idx[maxn], idy[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    Sval[(y - x)].insert(make_pair(x, y));
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < n; i++) {
    int ww = w[i];
    if (!Sval[ww].empty()) {
      ans[i] = *Sval[ww].begin();
      Sval[ww].erase(Sval[ww].begin());
    } else {
      puts("NO");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int f = ans[i].first, s = ans[i].second;
    if (idx[f].empty()) {
      idx[f].push_back(s);
    } else if (s < idx[f][idx[f].size() - 1]) {
      puts("NO");
      return 0;
    } else {
      idx[f].push_back(s);
    }
    if (idy[s].empty()) {
      idy[s].push_back(f);
    } else if (f < idy[s][idy[s].size() - 1]) {
      puts("NO");
      return 0;
    } else {
      idy[s].push_back(f);
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
