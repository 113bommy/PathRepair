#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 1995;
int n;
bool isIn(int x) { return 1 <= x && x <= n; }
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
  long long ans = 0;
  for (int s = 3; s <= 3 * n; s++)
    if (isIn(s - a - b) && isIn(s - b - d) && isIn(s - d - c) &&
        isIn(s - c - a))
      ans += n;
  cout << ans << "\n";
  return 0;
}
