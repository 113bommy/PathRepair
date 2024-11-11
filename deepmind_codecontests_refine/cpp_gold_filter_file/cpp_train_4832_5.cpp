#include <bits/stdc++.h>
const int MXN = 1e6 + 5;
const long long MNN = 1e5 + 1;
const long long MOD = 10;
const long long INF = 1e18;
const long long OO = 1e9 + 500;
using namespace std;
int n, a[MXN], k, cnt[MXN];
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  cin >> n >> k;
  int mn = OO, mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mn = min(a[i], mn);
    mx = max(a[i], mx);
  }
  for (int i = 1; i < MXN; i++) {
    cnt[i] += cnt[i - 1];
  }
  if (mn <= k) {
    cout << mn;
    return 0;
  } else {
    for (int i = mn; i >= k; i--) {
      long long cur = 0;
      for (int j = 1; j <= mx / i; j++) {
        cur += cnt[min(j * i + k, MXN - 1)] - cnt[j * i - 1];
      }
      if (cur == n) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
