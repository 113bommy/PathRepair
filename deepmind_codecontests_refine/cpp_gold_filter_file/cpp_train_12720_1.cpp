#include <bits/stdc++.h>
const long long MOD = 998244353;
const long long INF = 1e9;
const long long INFLL = 1e18;
using namespace std;
int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};
const int N = 5e5 + 228;
void solve() {
  int n;
  cin >> n;
  vector<int> cnt(2 * N);
  while (n--) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<int> mx0(2 * N), mx1(2 * N);
  for (int i = 1; i < 2 * N; i++) {
    mx0[i] = mx0[i - 1];
    mx1[i] = mx1[i - 1];
    if (cnt[i] >= 2)
      mx0[i] = mx1[i] = i;
    else if (cnt[i] == 1)
      mx1[i] = mx0[i], mx0[i] = i;
  }
  for (int i = 1; i < 2 * N; i++) cnt[i] += cnt[i - 1];
  long long ans = 0;
  for (int y = 2; y < N; y++) {
    long long cnt_sticks = 0;
    for (int i = 1; i * y < N; i++) {
      cnt_sticks += (cnt[i * y + y - 1] - cnt[i * y - 1]) * i;
    }
    if (cnt_sticks >= 2) {
      vector<int> best0(2 * N / y + 1, -1), best1(2 * N / y + 1, -1);
      for (int i = 0; i * y < N; i++) {
        int lst = i * y + y - 1;
        if (mx0[lst] >= i * y) {
          best0[i] = mx0[lst] % y;
          if (mx1[lst] >= i * y) {
            best1[i] = mx1[lst] % y;
          }
        }
      }
      long long res = 0;
      long long cur = -1;
      for (int i = N / y; i >= 0; i--) {
        cur = max((long long)best0[i], cur);
        if (cur != -1) {
          long long len = cur + i * y;
          long long sticksNOW = cnt_sticks - i;
          res = max(res, min(sticksNOW, len / 2));
        }
      }
      long long cur0 = -1, cur1 = -1;
      for (int i = N / y; i >= 0; i--) {
        if (best0[i] > cur0) {
          cur1 = cur0;
          cur0 = best0[i];
        } else if (best0[i] > cur1) {
          cur1 = best0[i];
        }
        if (best1[i] > cur0) {
          cur1 = cur0;
          cur0 = best1[i];
        } else if (best1[i] > cur1) {
          cur1 = best1[i];
        }
        if (cur0 != -1 && cur1 != -1) {
          {
            long long sticksNOW = cnt_sticks - 2 * i;
            long long len = cur1 + i * y;
            res = max(res, min(sticksNOW, len));
          }
          {
            long long sticksNOW = cnt_sticks - 2 * i - 1;
            long long len = cur0 + i * y;
            if (cnt[N] - cnt[len - 1] >= 2) res = max(res, min(sticksNOW, len));
          }
        }
      }
      ans = max(ans, res * y);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
