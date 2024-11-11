#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
pair<long long, int> a[MAXN];
long long pref[MAXN], suf[MAXN];
long long ans[MAXN];
void solve() {
  int n;
  long long A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  long long v;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &v);
    a[i] = make_pair(v, i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    pref[i] = pref[i - 1] + (a[i].first - a[i - 1].first) * (i - 1);
  }
  for (int i = n; i >= 1; i--) {
    if (i < n) {
      suf[i] = suf[i + 1];
    }
    suf[i] += A - a[i].first;
  }
  long long mx = a[1].first * cm;
  int id1, id2;
  long long mxl;
  int cnt_mx = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i].first == A) {
      cnt_mx++;
    }
  }
  mx += cf * cnt_mx;
  id2 = -1;
  id1 = -1;
  for (int i = 1; i <= n + 1; i++) {
    if (suf[i] > m) continue;
    long long rest = m - suf[i];
    long long cur = (n - i + 1) * cf;
    if (i > 1) {
      int j;
      if (pref[i - 1] <= rest) {
        j = i - 1;
      } else {
        j = upper_bound(pref, pref + i, rest) - pref - 1;
      }
      rest -= pref[j];
      long long cnt = j;
      long long level = a[j].first;
      level += rest / cnt;
      level = min(level, A);
      cur += level * cm;
      if (cur > mx) {
        mx = cur;
        id1 = i;
        id2 = j;
        mxl = level;
      }
    } else {
      cur += cm * A;
      mx = cur;
      id1 = 1;
      id2 = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int id = a[i].second;
    ans[id] = a[i].first;
  }
  for (int i = id1; i <= n; i++) {
    int id = a[i].second;
    ans[id] = A;
  }
  for (int i = 1; i <= id2; i++) {
    int id = a[i].second;
    ans[id] = mxl;
  }
  cout << mx << endl;
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", ans[i]);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
