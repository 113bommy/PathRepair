#include <bits/stdc++.h>
using namespace std;
long long a, b, w, x, c;
bool check(long long val) {
  return b + (val - (c - a)) * (w - x) >= (c - a) * x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> w >> x >> c;
  long long low = 0, high = 1e14;
  while (low < high) {
    long long mid = low + ((high - low) >> 1LL);
    if (check(mid))
      high = mid;
    else
      low = mid + 1LL;
  }
  cout << high << "\n";
  return 0;
}
