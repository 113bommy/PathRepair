#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 50, M = 8200;
int n, a[N];
vector<int> xs[M];
vector<pair<int, int> > ear;
bool vis[M];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> a[i], xs[a[i]].push_back(i);
  ear.push_back({0, 0});
  for (int v = 0; v < (M); ++v) {
    fill(vis, vis + M, 0);
    vector<pair<int, int> > gear;
    int c = 0;
    for (int i : xs[v]) {
      int r = c;
      while (r < (int)(ear).size() && ear[r].second < i) {
        if (!vis[ear[r].first]) {
          gear.push_back({ear[r]});
          vis[ear[r].first] = true;
        }
        r++;
      }
      for (int j = c; j < r; j++) {
        int nxt = ear[j].first ^ v;
        if (!vis[nxt]) {
          gear.push_back({nxt, i});
          vis[nxt] = true;
        }
      }
      c = r;
    }
    while (c < (int)(ear).size()) {
      if (!vis[ear[c].first]) {
        gear.push_back({ear[c]});
        vis[ear[c].first] = true;
      }
      c++;
    }
    ear = gear;
  }
  sort(begin(ear), end(ear));
  cout << (int)(ear).size() << '\n';
  for (int i = 0; i < ((int)(ear).size()); ++i) cout << ear[i].first << " ";
  cout << endl;
}
