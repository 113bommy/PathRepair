#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
void cnt(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a * b == 0) return;
  if (a == 1) {
    ans += b;
    return;
  }
  ans += (b / a);
  cnt(a, b - a * (b / a));
}
int main() {
  long long n, m, i, j, a, b;
  cin >> a >> b;
  cnt(a, b);
  cout << ans;
  return 0;
}
