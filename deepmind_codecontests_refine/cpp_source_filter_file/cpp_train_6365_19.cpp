#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, k, c[N];
long long a[N], b[N];
long long lowbit(long long x) { return x & -x; }
void add(long long x, long long val) {
  while (x <= k) {
    c[x] += val;
    x += lowbit(x);
  }
}
long long sum(long long x) {
  long long ret = 0;
  while (x) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
bool judge(long long x) {
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      long long tmp = (a[i] + j * x) / b[i] + 1;
      if (tmp > k - 1) break;
      add(tmp, 1);
      if (sum(tmp) > tmp) return false;
    }
  }
  for (int i = 1; i < k; i++)
    if (sum(i) > i) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long ans = -1;
  long long l = 0, r = 10, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (judge(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
