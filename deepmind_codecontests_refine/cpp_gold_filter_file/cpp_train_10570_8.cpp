#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000;
int n;
int t[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int maxl = -1;
  int sum = 0;
  for (int a = 0; a < n; ++a) {
    cin >> t[a];
    maxl = max(maxl, t[a]);
    sum += t[a];
  }
  if (sum - maxl >= maxl)
    cout << 1;
  else {
    cout << maxl - (sum - maxl) + 1;
  }
}
