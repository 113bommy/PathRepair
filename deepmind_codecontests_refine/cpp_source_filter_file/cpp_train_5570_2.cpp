#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[1000001], b[1000001], c[1000001], fix[10000001];
vector<int> v[10001];
void go(int x, int y) {
  if (y > m) return;
  fix[x] = 1;
  int p = 1;
  for (int i = 0; i < v[x].size(); i++) {
    if (!fix[v[x][i]]) {
      if (a[v[x][i]]) {
        p = 0, go(v[x][i], y + 1);
      } else {
        go(v[x][i], 0);
      }
    }
  }
  if (v[x].size() == 1 && x - 1) {
    ans += p;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> b[i] >> c[i];
    v[b[i]].push_back(c[i]);
    v[c[i]].push_back(b[i]);
  }
  go(1, a[1]);
  cout << ans;
}
