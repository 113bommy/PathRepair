#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void moha() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long double eps = 1e-10;
const long long N = 1e5 + 1, MOD = 1000000007;
int n, ans;
long long a[N], mn = 1e9 + 1;
long long calc(int x, int idx) {
  int a = 0, b = 1e9 + 1;
  while (a < b) {
    int mid = (a + b) / 2;
    if (1ll * n * mid + idx >= x)
      b = mid;
    else
      a = mid + 1;
  }
  return 1ll * a * n * idx;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = calc(a[i], i);
    if (a[i] < mn) {
      mn = a[i];
      ans = i + 1;
    }
  }
  cout << ans;
  return 0;
}
