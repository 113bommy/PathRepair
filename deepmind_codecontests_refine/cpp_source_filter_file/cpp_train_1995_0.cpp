#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
int N, K;
int arr[20013];
long long dp[2][20013];
int mxl[20013], mxr[20013];
long long overpass(pair<long long, long long> a, pair<long long, long long> b) {
  long long m1 = a.first, b1 = a.second, m2 = b.first, b2 = b.second;
  long long dm = m2 - m1, db = b1 - b2;
  if (dm == 0) {
    return (db > 0 ? 1000000007 : -1000000007);
  }
  return db / dm + (db % dm > 0);
}
long long f(pair<long long, long long> p, long long x) {
  return p.first * x + p.second;
}
void solve(int L, int R) {
  if (L == R) return;
  int mid = (L + R) >> 1;
  solve(L, mid);
  solve(mid + 1, R);
  mxl[mid] = 0;
  for (auto i = (mid)-1; i >= (L); i--) {
    mxl[i] = max(mxl[i + 1], arr[i]);
  }
  mxr[mid] = 0;
  for (auto i = (mid + 1); i < (R + 1); i++) {
    mxr[i] = max(mxr[i - 1], arr[i - 1]);
  }
  vector<pair<long long, long long> > lines;
  int iter = L - 1;
  for (auto i = (R + 1) - 1; i >= (mid + 1); i--) {
    while (iter + 1 <= mid && mxl[iter + 1] >= mxr[i]) {
      iter++;
      pair<long long, long long> cur = {mxl[iter],
                                        dp[0][iter] - iter * mxl[iter]};
      while (((int)((lines).size())) >= 2 &&
             overpass(lines.back(), lines[((int)((lines).size())) - 2]) >=
                 overpass(cur, lines.back())) {
        lines.pop_back();
      }
      lines.push_back(cur);
    }
    while (((int)((lines).size())) >= 2 &&
           f(lines[((int)((lines).size())) - 2], i) <=
               f(lines[((int)((lines).size())) - 1], i))
      lines.pop_back();
    long long res = (lines.empty() ? 1000000007 : f(lines.back(), i));
    ckmin(dp[1][i], res);
  }
  lines.clear();
  iter = mid + 1;
  for (auto i = (mid + 1); i < (R + 1); i++) {
    while (iter - 1 >= L && mxl[iter - 1] < mxr[i]) {
      iter--;
      pair<long long, long long> cur = {-iter, dp[0][iter]};
      while (((int)((lines).size())) >= 2 &&
             overpass(lines[((int)((lines).size())) - 2], lines.back()) >=
                 overpass(lines.back(), cur)) {
        lines.pop_back();
      }
      lines.push_back(cur);
    }
    while (((int)((lines).size())) >= 2 &&
           f(lines[((int)((lines).size())) - 2], mxr[i]) <=
               f(lines[((int)((lines).size())) - 1], mxr[i]))
      lines.pop_back();
    long long res =
        i * mxr[i] + (lines.empty() ? 1000000007 : f(lines.back(), mxr[i]));
    ckmin(dp[1][i], res);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(4);
  cin >> N >> K;
  for (auto i = (0); i < (N); i++) {
    cin >> arr[i];
  }
  for (auto i = (0); i < (N + 1); i++) {
    dp[1][i] = 1000000007;
  }
  dp[1][0] = 0;
  for (auto i = (0); i < (K); i++) {
    for (auto j = (0); j < (N + 1); j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 1000000007;
    }
    solve(0, N);
  }
  cout << dp[1][N] << '\n';
  return 0;
}
