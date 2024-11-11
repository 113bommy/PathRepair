#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-8;
int n, w;
long long ans;
struct coordinate {
  double a, b;
} a[N];
bool cmp(coordinate x, coordinate y) {
  return x.a == y.a ? x.b > y.b : x.a < y.a;
}
void Merge(int l, int mid, int r) {
  double b[N];
  for (int k = l, i = l, j = mid + 1; k <= r; ++k)
    if (j > r || i <= mid && a[i].b + eps < a[j].b)
      b[k] = a[i++].b;
    else
      b[k] = a[j++].b, ans += (long long)mid - i + 1;
  for (int i = l; i <= r; ++i) a[i].b = b[i];
}
void MergeSort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  MergeSort(l, mid);
  MergeSort(mid + 1, r);
  Merge(l, mid, r);
}
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1, x, v; i <= n; ++i) {
    scanf("%d%d", &x, &v);
    a[i].a = ((double)x) / ((double)(v - w));
    a[i].b = ((double)x) / ((double)(v + w));
  }
  sort(a + 1, a + 1 + n, cmp);
  MergeSort(1, n);
  printf("%lld", ans);
  return 0;
}
