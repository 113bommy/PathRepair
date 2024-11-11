#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAXN = 100001;
const int MAXM = 0;
int n, k, h;
struct frog {
  int v, m, ind;
};
frog a[MAXN];
int i, j;
bool ans[MAXN];
bool cmp(const frog &A, const frog &B) {
  if (A.m < B.m) return true;
  if (A.m > B.m) return false;
  if (A.v < B.v) return true;
  if (A.v > B.v) return false;
  return A.ind < B.ind;
}
double l, m, r;
bool iCan(double t) {
  int c = 0, i;
  for (i = 0; i < n; i++) {
    if (double(1 + c) * h / (double)a[i].v - t < eps) {
      c++;
      ans[i] = true;
    } else
      ans[i] = false;
    if (c == k) break;
  }
  if (c == k)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> k >> h;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].m);
    a[i].ind = i + 1;
  }
  for (i = 0; i < n; i++) scanf("%d", &a[i].v);
  sort(a, a + n, cmp);
  r = 10000000000LL;
  l = 0;
  for (int i = 0; i < 200; i++) {
    m = (r + l) / 2;
    if (iCan(m))
      r = m;
    else
      l = m;
  }
  iCan(r);
  int c = 0;
  for (i = 0; i < n; i++) {
    if (ans[i]) {
      printf("%d ", a[i].ind);
      c++;
    }
    if (c == k) break;
  }
  return 0;
}
