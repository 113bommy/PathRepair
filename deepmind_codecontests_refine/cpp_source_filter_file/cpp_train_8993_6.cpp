#include <bits/stdc++.h>
using namespace std;
int n, a[1101], L[3], R[3];
void dfs(int u) {
  if (u == 3) {
    bool f = 1;
    for (int i = 1; i <= n; i++) f &= a[i] == i;
    if (f) {
      cout << u << '\n';
      for (int i = u - 1; i >= 0; i--) cout << L[i] << ' ' << R[i] << '\n';
      exit(0);
    }
    return;
  }
  bool f = 1;
  for (int i = 1; i <= n; i++) f &= a[i] == i;
  if (f) {
    cout << u << '\n';
    for (int i = u - 1; i >= 0; i--) cout << L[i] << ' ' << R[i] << '\n';
    exit(0);
  }
  vector<int> pos = {1, n};
  for (int i = 2; i < n; i++)
    if (a[i] - a[i - 1] != a[i + 1] - a[i])
      pos.push_back(i), pos.push_back(i + 1);
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  if ((u == 1 && pos.size() > 16) || (u == 2 && pos.size() > 6)) return;
  int sz = pos.size();
  for (int l = 0; l < sz; l++)
    for (int r = l + 1; r < sz; r++) {
      L[u] = pos[l];
      R[u] = pos[r];
      reverse(a + L[u], a + R[u] + 1);
      dfs(u + 1);
      reverse(a + L[u], a + R[u] + 1);
    }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dfs(0);
}
