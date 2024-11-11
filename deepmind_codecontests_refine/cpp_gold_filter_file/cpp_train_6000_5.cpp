#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int a = max(2, abs(x1 - x2) + 1);
  int b = max(2, abs(y1 - y2) + 1);
  cout << 2 * (a + b) << endl;
}
