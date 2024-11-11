#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
int n, c, a[N], dp[N], cnt[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> c >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a, a + n);
  reverse(a, a + n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur + a[i] <= c) {
      cur += a[i];
    }
    dp[i] = cur;
  }
  if (dp[n - 1] != c) {
    cout << 0 << endl;
    return 0;
  }
  int ans = mod;
  for (int add = 0, j = n; add <= c; add++) {
    while (j > 0 && a[j - 1] <= add) j--;
    int now = 0;
    int p = j - 1;
    if (p != -1) now = dp[p];
    if (now + add <= c) {
      now += add;
      int i = p + 1;
      while (i < n) {
        if (now == c) break;
        int need = c - now;
        int l = i, r = n - 1, x = -1;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (a[mid] <= need) {
            x = mid;
            r = mid - 1;
          } else
            l = mid + 1;
        }
        if (x == -1) break;
        int cur = min(cnt[a[x]], (c - now) / a[x]);
        now += cur * a[x];
        i = x + cur;
      }
      if (now == c) continue;
      cout << add << endl;
      return 0;
    }
  }
  cout << "Greed is good\n";
  return 0;
}
