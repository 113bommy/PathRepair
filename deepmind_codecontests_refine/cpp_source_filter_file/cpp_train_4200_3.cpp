#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, possol, posves, a[100100], y, sol, ves, b[100100];
int main() {
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  posves = possol = 1;
  vector<pair<long long, long long>> v;
  while (posves <= m && possol <= n) {
    sol = a[possol];
    ves = b[posves];
    if (ves >= sol - x && ves <= sol + y) {
      v.push_back({possol, posves});
      possol++;
      posves++;
    } else if (ves < sol - y)
      posves++;
    else
      possol++;
  }
  cout << v.size() << endl;
  for (auto it : v) cout << it.first << " " << it.second << endl;
}
