#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 200010;
const int maxt = (1 << 22) + 100;
const int tsz = (1 << 20) + 10;
int a[maxn] = {};
int t[maxt] = {};
void recalc(int v) { t[v] = min(t[v * 2 + 1], t[v * 2 + 2]); }
void build(int v, int L, int R) {
  if (L == R) {
    t[v] = INF;
  } else {
    int m = (L + R) >> 1;
    build(v * 2 + 1, L, m);
    build(v * 2 + 2, m + 1, R);
    recalc(v);
  }
}
int query(int v, int l, int r, int L, int R) {
  if (l > R || L > r) return INF;
  if (L >= l && R <= r) return t[v];
  int m = (L + R) >> 1;
  int ans = min(query(v * 2 + 1, l, r, L, m), query(v * 2 + 2, l, r, m + 1, R));
  return ans;
}
void setval(int v, int pos, int L, int R, int val) {
  if (L == R) {
    t[v] = min(val, t[v]);
  } else {
    int m = (L + R) >> 1;
    if (pos <= m)
      setval(v * 2 + 1, pos, L, m, val);
    else
      setval(v * 2 + 2, pos, m + 1, R, val);
    recalc(v);
  }
}
int n;
int check(int k) {
  int cnt = 0;
  for (int i = 0; i < k; ++i) cnt += a[i];
  int curans = 0;
  for (int i = 0; i + k <= n; ++i) {
    int sogl = k - cnt;
    if (cnt <= 2 * sogl) curans++;
    cnt -= a[i];
    int nxt = i + k;
    if (nxt != n) cnt += a[nxt];
  }
  return curans;
}
int main() {
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; ++i) {
    int c = s[i] | 32;
    a[i] = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int best = 0;
  int cadd = 4 * maxn;
  int cursum = 0;
  build(0, 0, tsz - 1);
  setval(0, 0 + cadd, 0, tsz - 1, -1);
  for (int i = 0; i < n; ++i) {
    int curval = -1;
    if (a[i] == 0) curval = 2;
    cursum += curval;
    int tmp = query(0, 0, cursum + cadd, 0, tsz - 1);
    if (tmp < INF) {
      int curlen = i - tmp;
      best = max(best, curlen);
    }
    setval(0, cursum + cadd, 0, tsz - 1, i);
  }
  if (best == 0) printf("No solution"), exit(0);
  int ans = check(best);
  printf("%d %d", best, ans);
  return 0;
}
