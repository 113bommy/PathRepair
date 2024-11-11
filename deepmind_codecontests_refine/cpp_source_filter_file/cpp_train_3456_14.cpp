#include <bits/stdc++.h>
using namespace std;
int T, n, m, ans, i, p;
vector<int> v[200003];
int main() {
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> n;
    for (i = 0; i <= n; i++) v[i].clear();
    priority_queue<int> q;
    for (i = 0; i < n; i++) cin >> m >> p, v[m].push_back(p);
    for (int i = n; i > -1; i--) {
      for (int j = 0; j < v[i].size(); j++) q.push(-v[i][j]);
      while (q.size() > n - i) ans -= q.top(), q.pop();
    }
    cout << ans << endl;
  }
}
