#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m, t, r;
  cin >> m >> t >> r;
  int ghosts[m], lighted = 0;
  for (int i = 0; i < m; i++) cin >> ghosts[i];
  if (t < r)
    cout << -1 << endl;
  else {
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      while (!pq.empty() && pq.top() < ghosts[i]) pq.pop();
      int x = pq.size();
      for (int j = 0; j < r - x; j++) {
        pq.push(ghosts[i] - j - 1 + t);
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
