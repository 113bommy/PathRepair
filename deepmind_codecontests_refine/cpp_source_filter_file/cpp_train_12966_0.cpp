#include <bits/stdc++.h>
using namespace std;
void lets_hope_its_right() {
  long long n, m;
  cin >> n >> m;
  long long count = n * n;
  map<long long, long long> x, y;
  long long xcut = 0, ycut = 0;
  while (m--) {
    long long dx, dy;
    cin >> dx >> dy;
    if (!x.count(dx) && !y.count(dy)) {
      x[dx]++, y[dy]++;
      count -= n * 2 - 1 - (xcut + ycut);
      xcut++;
      ycut++;
    } else if (!x.count(dx)) {
      count -= (n - xcut);
      xcut++;
      x[dx]++;
    } else if (!y.count(dy)) {
      count -= n - ycut;
      ycut++;
      y[dy]++;
    }
    count = max(count, 0ll);
    cout << count << ' ';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) lets_hope_its_right();
}
