#include <bits/stdc++.h>
using namespace std;
int pri[300100];
int find(int x) { return pri[x] == x ? x : pri[x] = find(pri[x]); }
void join(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) pri[fx] = fy;
}
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n + 1; i++) pri[i] = i;
  while (t--) {
    int x, y;
    cin >> x >> y;
    join(x, y + n);
  }
  int ans = 0;
  for (int i = 1; i <= n + m; i++)
    if (find(i) == i) ans++;
  cout << ans - 1;
  return 0;
}
