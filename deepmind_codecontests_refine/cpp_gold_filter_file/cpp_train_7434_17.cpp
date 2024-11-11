#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n >> d;
  while (n--) {
    int t;
    cin >> t;
    pq.push(t);
  }
  int ans = 0;
  int m;
  cin >> m;
  while (m-- && !pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  while (m-- >= 0) ans -= d;
  cout << ans;
}
