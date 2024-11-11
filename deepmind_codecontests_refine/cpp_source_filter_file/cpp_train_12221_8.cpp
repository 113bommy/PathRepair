#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int Mx = 1e7;
const int mod = 1e9 + 7;
int n, k, a[N], lp[Mx + 5], b[Mx + 5];
long long ans, cnt[Mx + 5];
vector<int> p;
long long calc(long long x, long long y) {
  long long ans = 0;
  while (x) {
    x /= y;
    ans += x;
  }
  return ans;
}
int main() {
  for (int i = 2; i <= Mx; i++) {
    if (lp[i] == 0) {
      p.push_back(i);
      for (int j = i; j <= Mx; j += i)
        if (!lp[j]) lp[j] = i;
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  for (int i = Mx; i; i--) {
    b[i] += b[i + 1];
    if (b[i] == 0) continue;
    int x = i;
    while (x > 1) {
      int y = lp[x];
      while (x % y == 0) {
        cnt[y] += b[i];
        x /= y;
      }
    }
  }
  for (auto i : p) {
    if (cnt[i] == 0) continue;
    long long l = 1, r = 1ll * i * cnt[i];
    long long cur = -1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (calc(mid, i) >= cnt[i]) {
        cur = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    ans = max(ans, cur);
  }
  cout << ans;
  return 0;
}
