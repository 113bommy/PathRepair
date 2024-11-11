#include <bits/stdc++.h>
using namespace std;
long long x, y, z;
string s1, s2, s;
void memset_ll(long long a[], long long v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
void memset_s(char a[], char v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
int compare(const void* a, const void* b) {
  return (*(long long*)a - *(long long*)b);
}
void q_sort(long long a[], long long n) {
  qsort(a, n, sizeof(long long), compare);
}
static int compare1(const void* a, const void* b) {
  if (*(double*)a > *(double*)b)
    return 1;
  else if (*(double*)a < *(double*)b)
    return -1;
  else
    return 0;
}
void q_sort_d(double a[], long long n) {
  qsort(a, n, sizeof(double), compare1);
}
long long sum(long long n) {
  long long i = 0, a[6], j, k = 0;
  while (n > 0) {
    a[i] = n % 10;
    n /= 10;
    i++;
  }
  for (j = 0; j < i; j++) k += a[j];
  return k;
}
string trans_upper(string ss) {
  transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
  return ss;
}
int main() {
  long long t, l, p, q, r, i, j, h, k, e = 0, f = 0, g = 0;
  long long temp = 0, n, m, d = 0;
  cin >> n >> m;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  q_sort(a, n);
  i = a[n - 1];
  while (d < m) {
    d += i;
    e++;
    i--;
  }
  cout << e;
}
