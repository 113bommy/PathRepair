#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long inf = (1000000000 + 7);
void solve() {}
void Task() {
  int test;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int f = (n * y + 99) / 100;
  if (f < 0) f = 0;
  cout << f - x << "\n";
  return 0;
}
