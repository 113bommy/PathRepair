#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const long long LINF = (long long)2e18 + 7;
const int MOD = (int)1e9 + 7;
const unsigned long long P = 239017;
const unsigned long long MM = (unsigned long long)2147482661;
int n;
long long mx, cf, cm, m, pref[MAXN], ans[MAXN];
pair<long long, int> a[MAXN];
long long get(int l, int r) {
  if (l > r) return 0;
  return pref[r] - pref[l - 1];
}
bool f(long long minim, long long cur, int q) {
  int pos = lower_bound(a, a + n + 1, make_pair(minim, 0)) - a - 1;
  pos = min(pos, n - q);
  if (pos > (cur + get(1, pos)) / minim) return 0;
  return pos * minim - get(1, pos) <= cur;
}
int main() {
  cin >> n >> mx >> cf >> cm >> m;
  for (int i = 1; i <= (int)n; i++) {
    scanf("%I64d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= (int)n; i++) {
    pref[i] = pref[i - 1] + a[i].first;
  }
  long long answer = 0, ansmin = 0, ansq = 0;
  for (int i = 0; i < (int)n + 1; i++) {
    long long cur = m;
    if (i > (m + get(n - i + 1, n)) / mx) {
      break;
    }
    cur -= (i * mx - get(n - i + 1, n));
    long long left = 0, right = mx + 1;
    while (right - left > 1) {
      long long mid = (right + left) / 2;
      (f(mid, cur, i) ? left : right) = mid;
    }
    long long curmin = left;
    long long curans = i * cf + curmin * cm;
    if (curans > answer) {
      answer = curans, ansmin = curmin, ansq = i;
    }
  }
  cout << answer << '\n';
  for (int i = 1; i <= (int)n; i++) {
    if (n - ansq + 1 <= i) {
      ans[a[i].second] = mx;
    } else {
      ans[a[i].second] = max(ansmin, a[i].first);
    }
  }
  for (int i = 1; i <= (int)n; i++) {
    printf("%I64d ", ans[i]);
  }
  return 0;
}
