#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n, i, m;
  cin >> n >> m;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long int s = 0, j = 0, k = 0;
  i = 0;
  while (i < n) {
    if (m >= a[i]) {
      m -= a[i];
      s = max(s, i - j + 1);
      i++;
    }
    while (m < a[i] && i > j) {
      m += a[j];
      j++;
    }
    if (m < a[i] && i == j) i++, j++;
  }
  cout << s << endl;
}
