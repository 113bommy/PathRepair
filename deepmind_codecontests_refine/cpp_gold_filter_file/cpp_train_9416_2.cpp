#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 500;
void read(long long &x) {
  char ch;
  bool flag = 0;
  for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1);
       ch = getchar())
    ;
  for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar())
    ;
  x *= 1 - 2 * flag;
}
long long val[maxn];
long long sum[maxn];
long long n, m, k;
bool check(int ans) {
  long long flag = m;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    if (i - k < 1) {
      sum[i] = sum[i - 1];
      if (sum[i] + val[i] < ans) {
        flag -= (ans - (sum[i] + val[i]));
        sum[i] = (ans - val[i]);
      }
    } else {
      sum[i] = sum[i - 1];
      if (sum[i] - sum[i - k] + val[i] < ans) {
        flag -= (ans - (sum[i] - sum[i - k]) - val[i]);
        sum[i] += (ans - (sum[i] - sum[i - k]) - val[i]);
      }
    }
    if (flag < 0) return false;
  }
  return flag >= 0;
}
int main() {
  read(n), read(m), read(k);
  for (int i = 1; i <= n; i++) read(val[i]);
  long long l = 1, r = 1000000000001;
  long long ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
