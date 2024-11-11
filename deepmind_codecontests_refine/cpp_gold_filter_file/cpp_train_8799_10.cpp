#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int logn = 30;
const int inf = (int)1e9 + 5;
const long long mod = (int)1e9 + 7;
const long long base = 2204234849;
const long long l_inf = (long long)4e18;
const long double pi = acos(-1.0);
const long double eps = 1e-12;
int n, m, k;
int pos[maxn];
int ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  srand(566);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    pos[x] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      ans += pos[x];
      for (int q = 1; q <= k; q++)
        if (pos[q] < pos[x]) pos[q]++;
      pos[x] = 1;
    }
  }
  cout << ans;
  return 0;
}
