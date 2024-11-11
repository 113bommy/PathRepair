#include <bits/stdc++.h>
using namespace std;
void systemIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int solve() {}
int main() {
  systemIO();
  long long n, k;
  cin >> n >> k;
  long long l = 0, r = n, m;
  long long x, min;
  long long total;
  while (l != r) {
    m = (l + r) / 2;
    x = m;
    while (x >= 1) {
      total += x;
      x /= k;
    }
    if (total >= n)
      r = m;
    else
      l = m + 1;
    total = 0;
  }
  cout << l;
  return 0;
}
