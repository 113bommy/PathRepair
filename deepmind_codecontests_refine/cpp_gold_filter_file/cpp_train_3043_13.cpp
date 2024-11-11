#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
class cmp {
 public:
  bool operator()(const pair<long long int, long long int> &a,
                  const pair<long long int, long long int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  }
};
void solve() {
  long long int n, d, i;
  cin >> n >> d;
  long long int mx = (n * (n - 1)) / 2;
  if (d > mx) {
    cout << "NO" << endl;
    return;
  }
  string ans = "YES";
  long long int par[n + 1], dep[n + 1], curr = 0;
  par[1] = -1;
  dep[1] = 0;
  unordered_map<long long int, set<long long int>> m;
  m[0].insert(1);
  for (i = 2; i <= n; i++) {
    par[i] = i - 1;
    dep[i] = dep[i - 1] + 1;
    m[dep[i]].insert(i);
    curr += dep[i];
  }
  long long int vis[n + 1];
  memset(vis, 0, sizeof(vis));
  stack<long long int> leaf;
  leaf.push(n);
  long long int child[n + 1];
  for (i = 1; i < n; i++) child[i] = 1;
  child[n] = 0;
  while (curr > d) {
    curr = curr - 1;
    if (leaf.size()) {
      int flag = 0;
      while (leaf.size()) {
        long long int x = leaf.top();
        long long int h = dep[x];
        long long int prevpr = par[x];
        if (m.find(h - 2) == m.end()) {
          leaf.pop();
          continue;
        }
        long long int nwpr = -1;
        for (auto j : m[h - 2]) {
          long long int y = j;
          if (child[y] <= 1) {
            nwpr = y;
            break;
          }
        }
        if (nwpr == -1) {
          leaf.pop();
          continue;
        }
        child[prevpr]--;
        if (child[prevpr] == 0) leaf.push(prevpr);
        child[nwpr]++;
        m[dep[x]].erase(x);
        dep[x]--;
        m[dep[x]].insert(x);
        par[x] = nwpr;
        flag = 1;
        break;
      }
      if (flag == 0) {
        ans = "NO";
        break;
      }
    } else {
      ans = "NO";
      break;
    }
  }
  if (ans == "YES") {
    cout << ans << endl;
    for (i = 2; i <= n; i++) cout << par[i] << " ";
    cout << endl;
    return;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
