#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, k, x, ans, arr[N];
long long seg[4 * N];
void upd(int p, int second, int e, int idx, long long val) {
  if (second == e) return void(seg[p] = val);
  int m = (second + e) >> 1, a = p << 1, b = a | 1;
  idx <= m ? upd(a, second, m, idx, val) : upd(b, m + 1, e, idx, val);
  seg[p] = seg[a] | seg[b];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    upd(1, 0, n - 1, i, arr[i]);
  }
  for (int i = 0; i < n; ++i) {
    long long tmp = arr[i];
    for (int j = 0; j < k; ++j) {
      tmp *= x;
      upd(1, 0, n - 1, i, tmp);
      ans = max(ans, seg[1]);
    }
    upd(1, 0, n - 1, i, arr[i]);
  }
  cout << ans;
  return 0;
}
