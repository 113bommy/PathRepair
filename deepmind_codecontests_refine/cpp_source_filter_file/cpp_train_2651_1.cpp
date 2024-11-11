#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 1;
string s, ans;
int n;
int *shift, *tmp, *c, *dsort, *p;
int m, k, d;
void mult(int* a, int* b, int n, int* res) {
  for (int i = 0; i < n; ++i) res[i] = a[b[i]];
}
void pow(int* a, int n, int d, int* res) {
  for (int i = 0; i < n; ++i) tmp[i] = a[i];
  for (int i = 0; i < n; ++i) res[i] = i;
  while (d > 0) {
    if (d % 2 == 1) {
      mult(res, tmp, n, c);
      for (int i = 0; i < n; ++i) res[i] = c[i];
    }
    d /= 2;
    mult(tmp, tmp, n, c);
    for (int i = 0; i < n; ++i) tmp[i] = c[i];
  }
}
int main() {
  cin >> s;
  int n = s.size();
  shift = new int[n];
  tmp = new int[n];
  c = new int[n];
  dsort = new int[n];
  p = new int[n];
  scanf("%d", &m);
  ans = s;
  shift[0] = n - 1;
  for (int i = 1; i < n; ++i) shift[i] = i - 1;
  for (int j = 0; j < m; ++j) {
    scanf("%d%d", &k, &d);
    for (int i = 0; i < n; ++i) dsort[i] = i;
    int pos = 0;
    for (int i = 0; i < d; ++i) {
      for (int j = i; j < k; j += d) dsort[j] = pos++;
    }
    mult(shift, dsort, n, c);
    for (int i = 0; i < n; ++i) dsort[i] = c[i];
    pow(dsort, n, n - k + 1, p);
    for (int i = 0; i < n; ++i) dsort[i] = p[i];
    for (int i = 0; i < n; ++i) dsort[i] = (dsort[i] + n - k + 1) % n;
    for (int i = 0; i < n; ++i) ans[dsort[i]] = s[i];
    printf("%s", ans.c_str());
    s = ans;
  }
  return 0;
}
