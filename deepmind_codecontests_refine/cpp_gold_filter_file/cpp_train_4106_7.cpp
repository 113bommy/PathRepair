#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
int f[N], s[N];
long long ans;
long long solve() {
  int cnt = 0;
  int maxv = -1, minv = 2e9;
  for (int i = 0; i < (int)(m); i++)
    if (!s[i]) {
      maxv = max(maxv, f[i]);
      minv = min(minv, f[i]);
      cnt++;
    }
  long long res = 0;
  if (cnt >= 3) {
    res = max(res, (maxv - minv) * 2ll);
  }
  if (cnt >= 2) {
    for (int i = 0; i < (int)(m); i++)
      if (s[i]) {
        int r = n - f[i];
        res =
            max(res, maxv - minv + (long long)min(minv + r, n + n - minv - r) +
                         min(maxv + r, n + n - maxv - r));
      }
  }
  return res;
}
long long C(int n, int x) {
  if (x < 0 || x > n) return 0;
  if (x == 1) return n;
  if (x == 2) {
    return n * (long long)(n - 1) / 2;
  } else {
    return n * (long long)(n - 1) * (long long)(n - 2) / 6;
  }
}
void gao(long long goal) {
  int cnt = 0;
  int maxv = -1, minv = 2e9;
  map<int, int> ref;
  vector<int> v;
  for (int i = 0; i < (int)(m); i++)
    if (!s[i]) {
      maxv = max(maxv, f[i]);
      minv = min(minv, f[i]);
      cnt++;
      ref[f[i]]++;
      v.push_back(f[i]);
    }
  sort(v.begin(), v.end());
  if (cnt >= 3) {
    if ((maxv - minv) * 2ll == goal) {
      if (maxv == minv) {
        ans += C(cnt, 3);
      } else {
        ans += C(ref[minv], 2) * ref[maxv];
        ans += C(ref[maxv], 2) * ref[minv];
        ans += ref[minv] * (long long)ref[maxv] * (cnt - ref[maxv] - ref[minv]);
      }
    }
  }
  if (cnt >= 2) {
    for (int i = 0; i < (int)(m); i++)
      if (s[i]) {
        int r = n - f[i];
        long long tmp = maxv - minv +
                        (long long)min(minv + r, n + n - minv - r) +
                        min(maxv + r, n + n - maxv - r);
        if (tmp == goal) {
          if (n + n - minv - r <= minv + r) {
            ans += C(ref[minv], 2);
            ans += ref[minv] * (long long)(cnt - ref[minv]);
          } else if (maxv + r <= n + n - maxv - r) {
            ans += C(ref[maxv], 2);
            ans += ref[maxv] * (long long)(cnt - ref[maxv]);
          } else {
            int x = n - r;
            int lhs = lower_bound(v.begin(), v.end(), x) - v.begin();
            int mid = ref[x];
            int rhs = cnt - lhs - mid;
            ans += C(mid, 2);
            ans += lhs * mid;
            ans += lhs * rhs;
            ans += mid * rhs;
          }
        }
      }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)(m); i++) {
    cin >> s[i] >> f[i];
  }
  long long res = solve();
  for (int i = 0; i < (int)(m); i++) s[i] ^= 1;
  res = max(res, solve());
  gao(res);
  for (int i = 0; i < (int)(m); i++) s[i] ^= 1;
  gao(res);
  cout << ans << endl;
}
