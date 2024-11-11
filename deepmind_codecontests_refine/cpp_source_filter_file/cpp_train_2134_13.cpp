#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100030;
const long long MODD = 1000000009;
void do_case() {
  int a, b, c, d, x, y;
  cin >> x >> y >> a >> b >> c >> d;
  if (x > y) swap(x, y);
  pair<int, int> T[4] = {{a + c, max(b, d)},
                         {a + d, max(b, c)},
                         {b + c, max(a, d)},
                         {b + d, max(a, c)}};
  for (auto p : T) {
    int X, Y;
    tie(X, Y) = minmax(p.first, p.second);
    if (x <= X && y <= Y) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  do_case();
  return 0;
}
