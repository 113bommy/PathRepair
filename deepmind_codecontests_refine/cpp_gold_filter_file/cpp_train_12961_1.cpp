#include <bits/stdc++.h>
using namespace std;
void code() {
  int64_t x, y;
  cin >> x >> y;
  int64_t a = y;
  int64_t b = x;
  vector<int64_t> order;
  while (a > 1 || b > 1) {
    if (a == b) break;
    if (a > b) {
      int64_t t = (a - 1) / b;
      a -= t * b;
      order.push_back(-t);
    } else {
      int64_t t = (b - 1) / a;
      b -= t * a;
      order.push_back(t);
    }
  }
  if (a == 1 && b == 1) {
    for (int64_t o : order) cout << abs(o) << (o > 0 ? "A" : "B");
  } else
    cout << "Impossible";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int tt = 1; tt <= t; ++tt) {
    code();
  }
  return 0;
}
