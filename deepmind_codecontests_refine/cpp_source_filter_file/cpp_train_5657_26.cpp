#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
pair<double, double> A[MAXN];
int n, r, ord[MAXN], st[MAXN];
bool comp(int a, int b) {
  if (A[a].first != A[b].first) return A[a].first < A[b].first;
  return A[a].second < A[b].second;
}
int ccw(pair<double, double> a, pair<double, double> b,
        pair<double, double> c) {
  double tmp = a.first * b.second + b.first * c.second + c.first * a.second -
               a.second * b.first - b.second * c.first - c.second * a.first;
  if (tmp > 0) return 1;
  if (tmp < 0) return -1;
  return 0;
}
int main() {
  scanf("%d", &n);
  int i, m, ni;
  for (i = 1; i <= n; i++) scanf("%lf%lf", &A[i].first, &A[i].second);
  ni = n;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%lf%lf", &A[n + i].first, &A[n + i].second);
  n += m;
  for (i = 1; i <= n; i++) ord[i] = i;
  sort(ord + 1, ord + n + 1);
  st[++r] = ord[1];
  st[++r] = ord[2];
  for (i = 3; i <= n; i++) {
    while (r >= 2 && ccw(A[st[r - 1]], A[st[r]], A[ord[i]]) > 0) r--;
    st[++r] = ord[i];
  }
  for (i = n - 1; i >= 1; i--) {
    while (r >= 2 && ccw(A[st[r - 1]], A[st[r]], A[ord[i]]) > 0) r--;
    st[++r] = ord[i];
  }
  r--;
  for (i = 1; i <= r; i++)
    if (st[i] > ni) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
