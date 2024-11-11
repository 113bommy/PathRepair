#include <bits/stdc++.h>
using namespace std;
int n, mx, cperf, cmin;
long long m;
int a[100000];
inline bool cmp(const int &lhs, const int &rhs) { return a[lhs] < a[rhs]; }
int ord[100000];
int f, ind = 0, level;
void updateMin() {
  while (true) {
    while (ind + 1 < f && level >= a[ord[ind + 1]]) ++ind;
    long long ad = m / (ind + 1);
    if (ind + 1 < f) ad = min(ad, (long long)a[ord[ind + 1]] - level);
    if (ad == 0) break;
    level += ad;
    m -= ad * (ind + 1);
  }
}
int ansPos, ansLevel;
int main() {
  scanf("%d%d%d%d", &n, &mx, &cperf, &cmin);
  cin >> m;
  for (int i = 0; i < (int)(n); ++i) scanf("%d", a + i);
  for (int i = 0; i < (int)(n); ++i) ord[i] = i;
  sort(ord, ord + n, cmp);
  f = n;
  for (int ii = n - 1; ii >= 0; --ii) {
    int i = ord[ii];
    if (mx - a[i] > m) break;
    m -= mx - a[i];
    f = ii;
  }
  if (f == 0) {
    long long ans = (long long)cperf * n + (long long)cmin * mx;
    cout << ans << endl;
    for (int i = 0; i < (int)(n); ++i) printf("%d ", mx);
    printf("\n");
    return 0;
  }
  level = a[ord[0]];
  updateMin();
  long long ans = (long long)cperf * (n - f) + (long long)cmin * level;
  ansPos = f;
  ansLevel = level;
  while (f < n) {
    m += mx - max(a[ord[f]], level);
    ++f;
    updateMin();
    long long cur = (long long)cperf * (n - f) + (long long)cmin * level;
    if (cur > ans) {
      ans = cur;
      ansPos = f;
      ansLevel = level;
    }
  }
  cout << ans << endl;
  for (int i = ansPos; i < n; ++i) a[ord[i]] = mx;
  for (int i = 0; i < (int)(n); ++i) a[i] = max(a[i], ansLevel);
  for (int i = 0; i < (int)(n); ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
