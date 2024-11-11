#include <bits/stdc++.h>
using namespace std;
int N, M, X, K, Y;
vector<int> a, b;
long long myfunc(int l, int r) {
  int num = r - l - 1;
  if (!num) return 0LL;
  int tmp = *max_element(a.begin() + l + 1, a.begin() + r - 1);
  bool ok = 0;
  if (a[l] > tmp || a[r] > tmp) ok = 1;
  if (num >= K) {
    if (1LL * X <= 1LL * Y * K) {
      return 1LL * num / K * X + 1LL * num % K * Y;
    } else {
      if (ok) {
        return 1LL * num * Y;
      } else {
        return 1LL * X + 1LL * (num - K) * Y;
      }
    }
  } else {
    if (ok)
      return 1LL * Y * num;
    else
      return -1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> X >> K >> Y;
  a = vector<int>(N + 2);
  b = vector<int>(M + 2);
  for (int n = 1; n <= N; ++n) cin >> a[n];
  for (int m = 1; m <= M; ++m) cin >> b[m];
  long long ans = 0LL, tmp = 0LL;
  int aidx, bidx = 1;
  int l = 0, r = 1;
  bool ok = 1;
  for (aidx = 1; aidx <= N; ++aidx) {
    if (bidx <= M && a[aidx] == b[bidx]) {
      tmp = myfunc(l, r);
      if (tmp == -1)
        ok = 0;
      else
        ans += tmp;
      bidx++;
      l = aidx;
    }
    r++;
  }
  if (bidx <= M)
    cout << -1;
  else {
    tmp = myfunc(l, r);
    if (tmp == -1)
      ok = 0;
    else
      ans += tmp;
    if (ok)
      cout << ans;
    else
      cout << -1;
  }
  return 0;
}
