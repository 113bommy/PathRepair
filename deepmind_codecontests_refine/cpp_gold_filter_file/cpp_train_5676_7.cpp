#include <bits/stdc++.h>
using namespace std;
int toInt(string s) {
  istringstream sin(s);
  int t;
  sin >> t;
  return t;
}
template <class T>
string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
void chmin(T &t, T f) {
  if (t > f) t = f;
}
template <class T>
void chmax(T &t, T f) {
  if (t < f) t = f;
}
pair<int, int> a[100010];
int b[100010];
long long sum[100010];
int main() {
  int n, A;
  long long cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  a[n] = {A, n};
  for (i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i].first;
  long long ans = 0;
  long long r = m;
  long long bm = 0;
  int bf = 0;
  for (i = n; i >= 0; i--) {
    if (r < A - a[i].first) break;
    r -= A - a[i].first;
    long long score = cf * (n - i);
    int lo = 0, hi = A;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      long long p = lower_bound(a, a + i, make_pair(mid, -1)) - a;
      if (p * mid - sum[p] <= r)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    score += cm * hi;
    if (score >= ans) {
      ans = score;
      bf = i;
      bm = hi;
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i].first < bm) a[i].first = bm;
    if (i >= bf) a[i].first = A;
  }
  for (i = 0; i < n; i++) b[a[i].second] = a[i].first;
  cout << ans << endl;
  for (i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
