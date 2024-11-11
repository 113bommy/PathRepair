#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
const int maxe = 1e5 + 5;
const int maxt = 1e6 + 5;
bool side[maxn], fact[maxt];
int n, e, h[maxe][2];
vector<int> t[maxn];
int main() {
  srand(22);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    cin >> h[i][0] >> h[i][1];
    --h[i][0];
    --h[i][1];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    for (int j = 0; j < sz; j++) {
      int team;
      cin >> team;
      --team;
      mx = max(team, mx);
      t[i].push_back(team);
    }
  }
  while (1) {
    for (int i = 0; i < n; i++) {
      side[i] = rand() % 2;
    }
    int cnt = 0;
    for (int i = 0; i < e; i++) {
      int u = h[i][0], v = h[i][1];
      if (side[u] != side[v]) {
        ++cnt;
      }
    }
    if (2 * cnt >= e) {
      break;
    }
  }
  while (1) {
    for (int i = 0; i < mx; i++) {
      fact[i] = rand() % 2;
    }
    bool pass = true;
    for (int i = 0; i < n; i++) {
      bool ok = false;
      for (int team : t[i]) {
        if (fact[team] == side[i]) {
          ok = true;
        }
      }
      if (!ok) {
        pass = false;
        break;
      }
    }
    if (pass) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int team : t[i]) {
      if (fact[team] == side[i]) {
        cout << team + 1;
        break;
      }
    }
    if (i + 1 < n) {
      cout << ' ';
    }
  }
  cout << '\n';
  for (int i = 0; i <= mx; i++) {
    cout << 1 + fact[i];
    if (i + 1 <= mx) {
      cout << ' ';
    }
  }
  cout << '\n';
  return 0;
}
