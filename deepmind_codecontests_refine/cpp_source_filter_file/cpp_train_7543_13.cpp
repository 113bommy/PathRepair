#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const int N = 100000 + 5;
int n, a[N];
int q[N];
int b[N];
int q1[N], q2[N];
int c[N];
bool chack(int m, int e, int b[]) {
  memset(q1, 0, sizeof q1);
  memset(q2, 0, sizeof q2);
  for (int i = 0; i < (int)(e); ++i) ++q1[b[i]];
  for (int i = e; i < m; ++i) ++q2[b[i]];
  if (2 * e <= m) {
    for (int i = 0; i < (int)(m); ++i) c[i] = b[i];
    for (int i = 0; i < (int)(e); ++i) {
      int v = b[m - i - 1];
      if (!q1[v]) return false;
      --q1[v];
      c[i] = v;
    }
    for (int i = 0; i < (int)(m); ++i)
      if (c[i] != c[m - i - 1]) return false;
    return true;
  } else {
    for (int i = 1; i <= (int)(n); ++i)
      if (q1[i] < q2[i]) return false;
    return true;
  }
}
int get1(int m, int b[]) {
  int s = 1, f = m - 1;
  int re = m;
  while (s <= f) {
    int md = (s + f) / 2;
    if (chack(m, md, b)) {
      f = md - 1;
      re = md;
    } else {
      s = md + 1;
    }
  }
  return m - re;
}
int get(int m, int b[]) {
  int res = get1(m, b);
  reverse(b, b + m);
  return res + get1(m, b);
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(n); ++i) ++q[a[i]];
  int r = 0;
  for (int i = 1; i <= (int)(n); ++i) {
    r += q[i] % 2;
  }
  if (r != n % 2) {
    puts("0");
    return;
  }
  int in = -1;
  for (int i = 0; i < (int)(n); ++i) {
    if (a[i] != a[n - i - 1]) {
      in = i;
      break;
    }
  }
  if (in == -1) {
    long long val = (long long)(n * (n + 1)) / 2;
    cout << val << endl;
    return;
  }
  int m = 0;
  for (int i = in; i < n - in; ++i) b[m++] = a[i];
  long long res = 0;
  res += (long long)(in + 1) * (in + 1);
  res += (long long)(in + 1) * get(m, b);
  cout << res << endl;
}
void testgen() {
  FILE* f = fopen("input.txt", "w");
  fclose(f);
}
int main() {
  cout << fixed;
  cout.precision(15);
  cerr << fixed;
  cerr.precision(12);
  solve();
  return 0;
}
