#include <bits/stdc++.h>
const int N = 200000;
using namespace std;
int n, m, f[N];
vector<int> ent[N];
int ans[N];
int bad;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    ent[f[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    int val;
    cin >> val;
    if (ent[val].size() == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (ent[val].size() > 1) bad = 1;
    ans[i] = ent[val][0];
  }
  if (bad) {
    cout << "Ambiguity" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= m; i++) {
    if (i > 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
