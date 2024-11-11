#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
long long int temp[N];
int c[N];
int check(int mid, int s, int n) {
  for (int i = 1; i <= n; i++) {
    temp[i] = c[i] + 1ll * i * mid;
  }
  sort(temp + 1, temp + n);
  long long int ret = 0;
  for (int i = 1; i <= mid; i++) {
    if (temp[i] > 1000000000) return 0;
    ret += temp[i];
    if (ret > s) return 0;
  }
  if (ret <= s) return ret;
  return 0;
}
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> c[i];
  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid, s, n))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans << ' ' << check(ans, s, n) << '\n';
  return 0;
}
