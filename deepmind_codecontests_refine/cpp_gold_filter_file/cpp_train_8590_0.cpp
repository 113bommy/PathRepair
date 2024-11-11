#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> v[N];
int f;
void dfs(int i, int parent) {
  vis[i] = 1;
  for (int it : v[i]) {
    if (!vis[it]) {
      dfs(it, i);
    } else {
      if (it != parent) f = 1;
    }
  }
}
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  int cd = d;
  if (h > d || (d > 2 * h)) {
    cout << -1 << "\n";
    return 0;
  }
  if (n > 2 && d < 2) {
    cout << -1 << "\n";
    return 0;
  }
  for (int i = 1; i <= h; ++i) {
    cout << i << " " << i + 1 << "\n";
  }
  d -= h;
  if (d) {
    cout << 1 << " " << h + 2 << "\n";
    d--;
    for (int i = h + 2; i < h + 2 + d; ++i) cout << i << ' ' << i + 1 << "\n";
    for (int i = cd + 2; i <= n; ++i) cout << 1 << " " << i << "\n";
  } else {
    for (int i = h + 2; i <= n; ++i) cout << 2 << " " << i << "\n";
  }
}
