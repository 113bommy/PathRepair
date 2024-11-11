#include <bits/stdc++.h>
using namespace std;
bool ok(long long x, long long y) {
  if (x > y) swap(x, y);
  if (x == 0) return 0;
  if (!ok(x, y % x)) return 1;
  long long d = y / x - 1;
  return ((d % (x + 1LL)) % 2 + 100) % 2 == 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    puts(ok(x, y) ? "First" : "Second");
  }
}
