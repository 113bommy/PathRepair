#include <bits/stdc++.h>
using namespace std;
long long int mod = (1ll << 63);
vector<vector<int> > adj(1005);
vector<int> dis(1005);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int k1;
    cin >> k1;
    vector<int> v1(k1);
    for (int i = 0; i < k1; i++) cin >> v1[i];
    int k2;
    cin >> k2;
    vector<int> v2(k2);
    for (int i = 0; i < k2; i++) cin >> v2[i];
    cout << "B " << v2[0] << endl;
    int st;
    cin >> st;
    st--;
    for (int i = 0; i < n; i++) dis[i] = n + 2;
    queue<int> qu;
    qu.push(st);
    dis[st] = 0;
    while (qu.size()) {
      int cr = qu.front();
      for (int x : adj[cr]) {
        if (dis[x] > dis[cr] + 1) {
          dis[x] = dis[cr] + 1;
          qu.push(x);
        }
      }
      qu.pop();
    }
    int mind = n + 1, vrt = -1;
    for (int i = 0; i < k1; i++) {
      if (dis[v1[i] - 1] < mind) {
        mind = dis[v1[i] - 1];
        vrt = v1[i];
      }
    }
    cout << "A " << vrt << endl;
    cin >> st;
    int yes = 0;
    for (int i = 0; i < k2; i++) {
      if (v2[i] == st) yes = 1;
    }
    if (yes) {
      cout << "C " << vrt << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
