#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n, k, p, a[1005], b[2005], d[1005][2005];
bool used[2005];
vector<pair<int, int> > g[3005];
bool check(int x) {
  for (int i = 0, j = 0; i < k; i++) {
    if (abs(a[i] - b[j]) + abs(p - b[j]) <= x) j++;
    if (j == n) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + k);
  int lb = 0, ub = 2 * 1000000007;
  while (ub - lb > 1) {
    int mid = (lb + 1ll * ub) >> 1;
    if (check(mid))
      ub = mid;
    else
      lb = mid;
  }
  cout << ub << endl;
  return 0;
}
