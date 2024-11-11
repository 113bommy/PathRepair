#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[500005];
int sum[1000006];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int l = 1, r = 1;
  int ls = 1, rs = 0, max1 = 0;
  int sum1 = 0;
  for (; r <= n && l <= n; l++) {
    while (r <= n && sum1 <= k) {
      r++;
      sum[a[r]]++;
      if (sum[a[r]] == 1) sum1++;
    }
    if (r - l > max1) {
      max1 = r - l;
      ls = l, rs = r - 1;
    }
    sum[a[l]]--;
    if (sum[a[l]] == 0) sum1--;
  }
  cout << ls << " " << rs;
  return 0;
}
