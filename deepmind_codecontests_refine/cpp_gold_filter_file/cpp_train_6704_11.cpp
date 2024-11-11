#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
void debugarr(LL* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
LL a[10000010];
char str[100010];
set<LL> ans;
set<LL>::iterator it;
int main() {
  LL n, j, k, l, m, t, s = 0, d;
  LL i;
  cin >> n;
  a[0] = 1;
  for (i = 1; i < 63; i++) {
    a[i] = a[i - 1] * 2;
  }
  s = (LL)(double(sqrt(2 * n)) + 0.5);
  if (s * (s + 1) == 2 * n)
    if (s % 2 == 0) ans.insert(s + 1);
  for (i = 1; i < 63; i++) {
    LL lo = 1, hi = 2000000000, mid = (hi + lo) / 2;
    while (lo < hi) {
      mid = (hi + lo) / 2;
      s = n / mid - ((mid - 1)) / 2;
      if (a[i] - 1 > s)
        hi = mid;
      else if (a[i] - 1 < s)
        lo = mid + 1;
      else
        break;
    }
    if (s == a[i] - 1 && mid % 2 == 1 && n % mid == 0) ans.insert(mid * a[i]);
  }
  if (ans.size() == 0)
    printf("-1\n");
  else {
    it = ans.begin();
    for (; it != ans.end(); it++) cout << *it << endl;
  }
  return (0);
}
