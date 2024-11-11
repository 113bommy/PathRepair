#include <bits/stdc++.h>
using namespace std;
void HoH() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  HoH();
  int n, k, h;
  cin >> n >> k;
  int ans = 0;
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < n; i++) {
    cin >> h;
    ans += h / 10;
    pq.push({h % 10, -1 * h});
  }
  int s;
  while (k > 0) {
    if (10 - pq.top().first > k) break;
    s = pq.top().second;
    if (s == 100) break;
    s -= (10 - pq.top().first);
    k -= (10 - pq.top().first);
    ans++;
    pq.pop();
    pq.push({0, s});
  }
  cout << ans;
  return 0;
}
