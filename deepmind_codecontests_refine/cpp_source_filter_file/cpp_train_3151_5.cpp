#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
vector<int> a, b;
vector<int> topol;
bool vis[200005];
void topo(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  if (b[v] != -2) {
    topo(b[v]);
  }
  topol.push_back(v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.tie(0);
  ;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    num--;
    b.push_back(num);
  }
  for (int i = 0; i < N; i++)
    if (!vis[i]) topo(i);
  reverse(topol.begin(), topol.end());
  ll ans = 0;
  vector<int> res, rev;
  for (auto i : topol) {
    ans += a[i];
    if (a[i] >= 0) {
      if (b[i] != -2) a[b[i]] += a[i];
      res.push_back(i);
    } else {
      rev.push_back(i);
    }
  }
  reverse(rev.begin(), rev.end());
  cout << ans << endl;
  for (auto x : res) cout << x + 1 << " ";
  for (auto x : rev) cout << x + 1 << " ";
  return 0;
}
