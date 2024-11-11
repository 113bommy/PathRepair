#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn], r[maxn];
bool cmp(int x, int y) {
  if (a[x] != a[y]) return a[x] > a[y];
  return x < y;
}
double L[maxn], R[maxn];
double two[maxn];
int main() {
  two[0] = 1;
  for (int i = 1; i < maxn; i++) two[i] = two[i - 1] / 2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) r[i] = i;
  sort(r + 1, r + 1 + n, cmp);
  set<int> S;
  S.insert(0);
  S.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    int id = r[i];
    S.insert(id);
    set<int>::iterator it = S.find(id);
    L[id] = 0;
    for (int j = 1; j <= 100; j++) {
      int xx = *it;
      it--;
      L[id] += two[j] * (xx - (*it));
      if (it == S.begin()) break;
    }
    it = S.find(id);
    for (int j = 0; j <= 100; j++) {
      int xx = *it;
      it++;
      if (it == S.end()) break;
      R[id] += two[j] * (*it - xx);
    }
  }
  double ans = 0;
  double ss = 0;
  for (int i = 1; i <= n; i++) {
    ss += L[i] * R[i] * a[i];
    if (ss >= 1e10) {
      ans += ss / n / n;
      ss = 0;
    }
  }
  ans += ss / n / n;
  printf("%.15f\n", ans);
}
