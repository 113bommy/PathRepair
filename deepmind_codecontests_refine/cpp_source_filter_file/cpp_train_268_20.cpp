#include <bits/stdc++.h>
using namespace std;
int sol(const vector<long long>& a, int n, int m, long long t) {
  long long s = 0;
  for (int i = 0; i < m; i++) s += a[i];
  int ans = 0;
  for (int i = 0; i <= n && s * i <= t; i++) {
    int cnt = (m + 1) * i;
    long long r = t - s * i;
    for (int j = 0; j < m && r >= a[j]; j++) {
      int c = min(r / a[j], (long long)n);
      r -= a[j] * c;
      cnt += c;
    }
    ans = max(ans, cnt);
  }
  return ans;
}
int main() {
  int n, m;
  long long t;
  scanf("%d%d%lld", &n, &m, &t);
  vector<long long> a(m);
  for (int i = 0; i < m; i++) scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  printf("%d\n", sol(a, n, m, t));
}
