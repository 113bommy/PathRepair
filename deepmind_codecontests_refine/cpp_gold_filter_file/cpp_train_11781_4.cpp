#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> adj[N];
bool operator==(vector<int> a, vector<int> b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i]) return false;
  return true;
}
int dist(int x, int y) { return y >= x ? y - x : n - x + y; }
int Z[N];
void CalcZ() {
  Z[1] = n;
  int l = 1, r = 1;
  for (int i = 2; i <= n; i++) {
    if (i > r) {
      l = r = i;
      while (r <= n && adj[r] == adj[r - l + 1]) r++;
      Z[i] = r - l;
      r--;
    } else {
      int k = i - l + 1;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        l = i;
        while (r <= n && adj[r] == adj[r - l + 1]) r++;
        Z[i] = r - l;
        r--;
      }
    }
  }
}
int main() {
  if (fopen("exam.inp", "r"))
    freopen("exam.inp", "r", stdin), freopen("exam.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(dist(x, y));
    adj[y].push_back(dist(y, x));
  }
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  CalcZ();
  for (int i = 1; i <= n; i++) Z[i] = (i + Z[i] - 1 == n);
  for (int i = 2; i <= n; i++)
    if (Z[i] && Z[n - i + 2]) {
      puts("Yes");
      return 0;
    }
  puts("No");
}
