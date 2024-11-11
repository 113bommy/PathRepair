#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, l, r, q, t, n, z, test, x, y, k;
  cin >> n;
  long long count1 = 0, total1 = 0, count2 = 0, total2 = 0;
  while (n--) {
    cin >> i >> j >> k;
    if (i == 1) {
      count1 += j;
      total1 += k;
    } else {
      count2 += j;
      total2 += k;
    }
  }
  if (count1 >= total1)
    cout << "LIVE\n";
  else
    cout << "DEAD\n";
  if (count2 >= total2)
    cout << "LIVE\n";
  else
    cout << "DEAD\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
