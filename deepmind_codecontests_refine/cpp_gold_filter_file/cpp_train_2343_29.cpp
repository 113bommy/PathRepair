#include <bits/stdc++.h>
using namespace std;
const int N = 200;
typedef long long matrix[N][N];
const long long MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 2 * acos(0);
const int maxn = 1e6 + 6;
int q[1000100], a[8000100];
long long ans = 0;
int main() {
  cin.sync_with_stdio(false);
  int n;
  int qmax = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
    if (q[i] > qmax) qmax = q[i];
    a[q[i]]++;
  }
  int i = 0;
  while (i <= 2000000) {
    ans += a[i] % 2;
    a[i + 1] += a[i] / 2;
    i++;
  }
  cout << ans;
}
