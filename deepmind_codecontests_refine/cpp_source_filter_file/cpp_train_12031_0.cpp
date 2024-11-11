#include <bits/stdc++.h>
using namespace std;
int n, i, flag, a1, b1, a2, b2;
long long int ans;
priority_queue<pair<int, int> > pq;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 + b1 > a2 + b2) {
      ans -= b1 + b2;
      pq.push(make_pair((a1 + b1), (a2 + b2)));
    } else if (a1 + b1 == a2 + b2) {
      ans += a1 - b2;
    } else if (a1 >= b2 && a1 >= b1) {
      ans += a1 - b2;
    } else if (b1 >= a1 && b2 >= a1) {
      ans -= b1 - a2;
    }
  }
  flag = 0;
  while (!pq.empty()) {
    if (!flag) ans += pq.top().first;
    if (pq.top().second != -1) pq.push(make_pair((pq.top().second), (-1)));
    pq.pop();
    flag ^= 1;
  }
  cout << ans << endl;
  return 0;
}
