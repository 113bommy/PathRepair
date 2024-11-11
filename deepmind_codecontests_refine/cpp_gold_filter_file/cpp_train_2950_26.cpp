#include <bits/stdc++.h>
using namespace std;
int n, k, h;
int m[100001];
int v[100001];
int id[100001];
int match[100001];
int res[100001];
double eps = 1e-9;
void qsort1(int, int);
void qsort2(int, int);
bool ok(double);
int main() {
  cin >> n >> k >> h;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
    id[i] = i;
  }
  for (int i = 1; i <= n; i++) cin >> v[i];
  qsort1(1, n);
  int first = 1;
  for (int i = 2; i <= n; i++)
    if (m[i] != m[i - 1]) {
      qsort2(first, i - 1);
      first = i;
    }
  if (m[n] == m[n - 1]) qsort2(first, n);
  double hi, lo;
  lo = 0;
  hi = 1e9;
  for (int j = 1; j <= 100; j++) {
    double mid = (hi + lo) / 2;
    if (ok(mid)) {
      hi = mid;
      for (int i = 1; i <= k; i++) res[i] = match[i];
    } else
      lo = mid;
  }
  for (int i = 1; i <= k; i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
bool ok(double mid) {
  int j = 1;
  for (int i = 1; i <= k; i++) {
    while (j <= n && double(i * h) / double(v[j]) > mid + eps) j++;
    if (j > n) return false;
    match[i] = id[j];
    j++;
  }
  return true;
}
void qsort1(int l, int r) {
  if (l >= r) return;
  int i = l;
  int j = r;
  int mid = m[(l + r) / 2];
  while (i < j) {
    while (m[i] < mid) i++;
    while (mid < m[j]) j--;
    if (i <= j) {
      swap(m[i], m[j]);
      swap(v[i], v[j]);
      swap(id[i], id[j]);
      i++;
      j--;
    }
  }
  qsort1(i, r);
  qsort1(l, j);
}
void qsort2(int l, int r) {
  if (l >= r) return;
  int i = l;
  int j = r;
  int mid = v[(l + r) / 2];
  while (i < j) {
    while (v[i] < mid) i++;
    while (mid < v[j]) j--;
    if (i <= j) {
      swap(v[i], v[j]);
      swap(m[i], m[j]);
      swap(id[i], id[j]);
      i++;
      j--;
    }
  }
  qsort2(i, r);
  qsort2(l, j);
}
