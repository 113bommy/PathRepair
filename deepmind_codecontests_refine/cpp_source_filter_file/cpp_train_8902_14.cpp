#include <bits/stdc++.h>
using namespace std;
const int M = 100001;
int n, vis[M];
vector<int> v;
string s;
void solve() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int x = 0, c = 0;
  while (x >= 0 && x <= n) {
    if (vis[x]) {
      cout << "INFINITE";
      return;
    }
    vis[x] = 1;
    if (s[x] == '>')
      c += v[x];
    else
      c += v[x];
  }
  cout << "FINITE";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
