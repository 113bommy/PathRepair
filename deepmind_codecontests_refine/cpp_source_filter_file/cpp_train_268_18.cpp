#include <bits/stdc++.h>
using namespace std;
int n, k, m, a[49];
long long cs[49];
int get(int r, int sum) {
  int ret = 0;
  for (int i = 1; i <= k; ++i) {
    int rep = n - r;
    while (sum >= a[i] && rep--) {
      sum -= a[i];
      ++ret;
    }
  }
  return ret;
}
int play(int lastC) {
  int ret = 0, temp = m;
  for (int r = 1; r <= n; ++r) {
    if (temp >= cs[lastC]) {
      temp -= cs[lastC];
      int can = lastC * r;
      if (lastC == k) {
        can += r;
      }
      if (r + 1 <= n) {
        can += get(r + 1, temp);
      }
      ret = max(ret, can);
    } else {
      break;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> m;
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + k + 1);
  for (int i = 1; i <= k; ++i) {
    cs[i] = cs[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans = max(ans, play(i));
  }
  cout << ans;
  return 0;
}
