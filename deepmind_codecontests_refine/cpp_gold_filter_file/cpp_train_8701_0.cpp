#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int K = 51;
const int INF = 1e9 + 7;
int a[N], b[N];
int aa[N], bb[N];
int n, p, k, r, s;
short dp[N][N][K][2];
int oo[N][N];
short calc(int idx, int canp, int cnt1, int cnt2) {
  int who = (cnt1 > 0 ? 0 : 1);
  auto &res = dp[idx][canp][cnt1 + cnt2][who];
  if (res != -1) return res;
  if (idx >= n) return res = 0;
  assert(cnt1 == 0 || cnt2 == 0);
  res = (cnt1 > 0 ? a[idx] : 0) + (cnt2 > 0 ? b[idx] : 0) +
        calc(idx + 1, canp, cnt1 > 0 ? cnt1 - 1 : 0, cnt2 > 0 ? cnt2 - 1 : 0);
  if (canp >= 1) {
    if (cnt1 > 0) {
      assert(cnt2 == 0);
      int nr = min(n, idx + cnt1);
      int ncost2 = oo[idx][nr - 1];
      int ncnt22 = k - (nr - idx);
      res = max(res, (short)(ncost2 + calc(nr, canp - 1, 0, ncnt22)));
    }
    if (cnt2 > 0) {
      int nr = min(n, idx + cnt2);
      int ncost1 = oo[idx][nr - 1];
      int ncnt11 = k - (nr - idx);
      res = max(res, (short)(ncost1 + calc(nr, canp - 1, ncnt11, 0)));
    }
    if (cnt1 == 0 && cnt2 == 0) {
      res = max(res, (short)(a[idx] + calc(idx + 1, canp - 1, k - 1, 0)));
      res = max(res, (short)(b[idx] + calc(idx + 1, canp - 1, 0, k - 1)));
    }
  }
  if (canp >= 2) {
    int nidx = min(n, idx + k);
    res = max(res, (short)(oo[idx][nidx - 1] + calc(nidx, canp - 2, 0, 0)));
  }
  return res;
}
int main() {
  cin >> n >> p >> k;
  cin >> r;
  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    x--;
    a[x]++;
  }
  cin >> s;
  for (int i = 0; i < s; i++) {
    int x;
    cin >> x;
    x--;
    b[x]++;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      oo[i][j] = a[j] | b[j];
      if (j > i) oo[i][j] += oo[i][j - 1];
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = calc(0, p, 0, 0);
  cout << ans;
}
