#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], m, n, i;
vector<int> pos[maxn];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x].push_back(i);
  }
  bool flag = 0;
  for (i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (!pos[x].size()) {
      cout << "Impossible";
      return 0;
    }
    if (pos[x].size() > 1) {
      flag = 1;
      continue;
    }
    a[i] = pos[x][0];
  }
  if (flag) {
    cout << "Ambigutity";
    return 0;
  }
  cout << "Possible" << endl;
  for (i = 1; i <= m; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
