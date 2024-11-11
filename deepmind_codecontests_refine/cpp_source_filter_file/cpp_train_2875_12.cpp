#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
void intimain() {
  ios_base::sync_with_stdio(0);
  freopen("1.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int main() {
  int n, k, res = 0;
  ;
  cin >> n >> k;
  if (n == 1 || n == k || k == 0) {
    cout << 0 << " " << 0;
    return 0;
  } else if (k >= n / 3) {
    res += 2 * (n / 3);
    k -= (n / 3);
  } else {
    res += 2 * k;
    k = 0;
  }
  if (k > 0 && n % 3 == 2) {
    res++;
    k--;
  }
  if (n % 3 == 1) k--;
  cout << 1 << " " << res - k;
}
