#include <bits/stdc++.h>
using namespace std;
int val[101];
int solve(vector<priority_queue<int>> pq, int x, int m, int n) {
  int i = x, ans = 0, temp;
  while (m) {
    if (!pq[i].empty()) {
      if (pq[i].top() > n)
        temp = pq[i].top() % n;
      else
        temp = pq[i].top();
      val[temp]++;
      pq[i].pop();
    }
    if (val[i] > 0) {
      m -= val[i];
      val[i] = 0;
    }
    if (i == n)
      i = 1;
    else
      i++;
    ans++;
  }
  return ans;
}
int main() {
  int n, m, x, y, ans = 0;
  cin >> n >> m;
  vector<priority_queue<int>> pq(n + 1);
  memset(val, 0, sizeof(val));
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (y < x) {
      y = n - x + y;
    }
    pq[x].push(y);
  }
  for (int i = 1; i <= n; i++) {
    memset(val, 0, sizeof(val));
    cout << solve(pq, i, m, n) - 1 << " ";
  }
}
