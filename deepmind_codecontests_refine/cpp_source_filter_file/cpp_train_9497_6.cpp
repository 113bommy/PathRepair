#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = INT_MAX / 2;
const long long LLINF = 9223372036854775807 / 2;
int deg[MAXN];
vector<int> g[MAXN];
bool used[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  set<int> s;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) {
      s.insert(i);
      used[i] == true;
    }
  while (s.size() > 1) {
    int l = *s.begin();
    s.erase(l);
    int r = *s.begin();
    s.erase(r);
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int ans;
    cin >> ans;
    {
      if (ans == l || ans == r) {
        cout << "! " << ans << endl;
        return 0;
      }
    }
    for (auto e : g[l]) {
      deg[e]--;
      if (deg[e] <= 1 && used[e] == false) {
        s.insert(e);
        used[e] = true;
      }
    }
    for (auto e : g[r]) {
      deg[e]--;
      if (deg[e] <= 1 && used[e] == false) {
        s.insert(e);
        used[e] = true;
      }
    }
  }
  int ans = *s.begin();
  cout << "! " << ans << endl;
}
