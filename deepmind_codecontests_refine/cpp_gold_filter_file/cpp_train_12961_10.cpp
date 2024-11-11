#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void dfs(long long x, long long y) {
  if (x == y) return;
  if (x > y) {
    cout << (x - 1) / y << "A";
    dfs((x - 1) % y + 1, y);
  } else {
    cout << (y - 1) / x << "B";
    dfs(x, (y - 1) % x + 1);
  }
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (gcd(x, y) > 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  dfs(x, y);
}
