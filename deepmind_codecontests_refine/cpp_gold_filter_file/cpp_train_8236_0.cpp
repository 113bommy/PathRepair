#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long d[300002];
long long df[300002];
long long c[300002];
int bef[300002];
int aft[300002];
struct SparseMin {
  long long sp[20][300002];
  void build() {
    for (int LOG = 1; LOG < 20; LOG++)
      for (int i = 0; i <= n + 1; i++) {
        int mid = min(i + (1 << (LOG - 1)), n + 1);
        sp[LOG][i] = min(sp[LOG - 1][i], sp[LOG - 1][mid]);
      }
  }
  int lg2(long long x) {
    int ret = 0;
    while (x != 1) x /= 2, ret++;
    return ret;
  }
  long long get(int a, int b) {
    int pw = lg2(b - a + 1);
    int mid = b - (1 << pw) + 1;
    return min(sp[pw][a], sp[pw][mid]);
  }
};
SparseMin pr;
SparseMin su;
long long goLeft(int lo, int hi) { return pr.sp[0][hi] - pr.get(lo - 1, hi); }
long long goRight(int lo, int hi) { return su.sp[0][lo] - su.get(lo, hi + 1); }
long long mxov(int lo, int mid, int hi) {
  return max(0LL, goLeft(lo, mid - 1) + goRight(mid, hi));
}
long long sq(long long x) { return x * x; }
int main() {
  cout << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> d[i] >> c[i], c[i] = k - c[i];
  for (int i = 1; i <= n; i++) df[i] = sq(d[i] - d[i - 1]);
  for (int i = 1; i <= n; i++) pr.sp[0][i] = c[i] + pr.sp[0][i - 1];
  pr.build();
  for (int i = n; i >= 1; i--) su.sp[0][i] = c[i] + su.sp[0][i + 1];
  su.build();
  vector<int> s;
  s.push_back(1);
  bef[1] = 1;
  for (int i = 2; i <= n; i++) {
    while (s.size() != 1 && df[s.back()] <= df[i]) s.pop_back();
    bef[i] = s.back();
    s.push_back(i);
  }
  s.clear();
  s.push_back(n + 1);
  for (int i = n; i >= 1; i--) {
    while (s.size() != 1 && df[s.back()] <= df[i]) s.pop_back();
    aft[i] = s.back() - 1;
    s.push_back(i);
  }
  long long ret = 0;
  for (int i = 1; i <= n; i++) ret = max(ret, c[i]);
  for (int i = 2; i <= n; i++) ret = max(ret, mxov(bef[i], i, aft[i]) - df[i]);
  cout << ret;
  return 0;
}
