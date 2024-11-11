#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, sum[200100], res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> sum[i], sum[i] += sum[i - 1];
  res = sum[n];
  for (int i = n - 2; i >= 1; i--) res = max(sum[i] - res, res);
  cout << res;
  return 0;
}
