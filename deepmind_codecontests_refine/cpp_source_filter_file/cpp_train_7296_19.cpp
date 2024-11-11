#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 2e18 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long m, n, res;
  cin >> m >> n;
  vector<int> a;
  vector<int> r(n);
  for (int i = (0); i < (n); i++) {
    cout << 1 << endl;
    cin >> res;
    if (res == 0) exit(0);
    if (res == -1)
      r[i] = 0;
    else
      r[i] = 1;
  }
  int lo = 0, hi = m, c = -1;
  while (lo <= hi) {
    c++;
    int mid = (lo + hi) / 2;
    cout << mid << endl;
    cin >> res;
    if (res == 0) exit(0);
    if (res == 1) {
      if (r[c] == 1)
        lo = mid + 1;
      else
        hi = mid - 1;
    } else if (res == -1) {
      if (r[c] == 0)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
  }
  return 0;
}
