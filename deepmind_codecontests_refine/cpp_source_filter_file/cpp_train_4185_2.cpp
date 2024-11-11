#include <bits/stdc++.h>
using namespace std;
int n, m, p[100010];
long long a[100010], colsum[100010], rowsum[100010];
bool cmp1(int a, int b) { return rowsum[a] < rowsum[b]; }
bool cmp2(int a, int b) { return colsum[a] < colsum[b]; }
long long cal1(int n, int m, long long colsum[], long long rowsum[], int b) {
  long long tmp = 0;
  for (int i = 0; i < n; ++i) p[i] = i;
  if (b)
    sort(p, p + n, cmp1);
  else
    sort(p, p + n, cmp2);
  for (int i = 0; i < min(4, n); ++i) tmp += rowsum[p[i]];
  return tmp;
}
long long cal2(int n, int m, long long colsum[], long long rowsum[], int b) {
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) colsum[j] -= b ? a[i * m + j] : a[i + j * m];
    for (int j = 0; j < m; ++j) p[j] = j;
    if (b)
      sort(p, p + m, cmp2);
    else
      sort(p, p + m, cmp1);
    long long tmp = 0;
    for (int j = 0; j < min(3, m); ++j) tmp += colsum[p[j]];
    ans = max(ans, tmp + rowsum[i]);
    for (int j = 0; j < m; ++j) colsum[j] += b ? a[i * m + j] : a[i + j * m];
  }
  return ans;
}
long long cal3(int n, int m, long long colsum[], long long rowsum[], int b) {
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < m; ++k)
        colsum[k] -=
            b ? a[i * m + k] + a[j * m + k] : a[k * m + i] + a[k * m + j];
      long long mx = 0, inf_max = 0;
      for (int k = 0; k < m; ++k) {
        if (colsum[k] > mx) {
          inf_max = mx;
          mx = colsum[k];
        } else if (colsum[k] > inf_max) {
          inf_max = colsum[k];
        }
      }
      ans = max(ans, mx + inf_max + rowsum[i] + rowsum[j]);
      for (int k = 0; k < m; ++k)
        colsum[k] +=
            b ? a[i * m + k] + a[j * m + k] : a[k * m + i] + a[k * m + j];
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lld", &a[i * m + j]);
      rowsum[i] += a[i * m + j];
      colsum[j] += a[i * m + j];
    }
  }
  long long ans = 0;
  ans = max(ans, cal1(n, m, colsum, rowsum, 1));
  ans = max(ans, cal1(m, n, rowsum, colsum, 0));
  ans = max(ans, cal2(n, m, colsum, rowsum, 1));
  ans = max(ans, cal2(m, n, rowsum, colsum, 0));
  if (n < 2 || m < 2) {
    printf("%lld\n", ans);
    return 0;
  }
  if (n < m)
    ans = max(ans, cal3(n, m, colsum, rowsum, 1));
  else
    ans = max(ans, cal3(m, n, rowsum, colsum, 0));
  printf("%lld\n", ans);
}
