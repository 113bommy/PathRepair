#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
int main() {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  vector<i64> happy(n + 1);
  i64 pt = 0;
  for (int i = 0; i < m; i++) {
    i64 a, b, t;
    scanf("%lld %lld %lld", &a, &b, &t);
    i64 canMove = d * (t - pt);
    deque<ii64> dq;
    for (int i = 1; i <= min<i64>(1 + canMove, n); i++) {
      while (!dq.empty() && dq.back().second < happy[i]) dq.pop_back();
      dq.emplace_back(i, happy[i]);
    }
    for (int i = 1; i <= n; i++) {
      while (!dq.empty() && i - dq.front().first > canMove) dq.pop_front();
      if (i + canMove <= n) {
        while (!dq.empty() && dq.back().second < happy[i + canMove])
          dq.pop_back();
        dq.emplace_back(i + canMove, happy[i + canMove]);
      }
      happy[i] = dq.front().second;
      happy[i] += b - abs(a - i);
    }
    pt = t;
  }
  printf("%lld\n", *max_element(happy.begin() + 1, happy.end()));
  return 0;
}
