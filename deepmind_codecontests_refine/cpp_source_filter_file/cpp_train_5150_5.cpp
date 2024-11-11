#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 1100;
const int M = 5005;
const int oo = 10000 * 10000 * 10;
const int mn = 100000;
int n;
int an;
int a[N];
double lo, hi;
void solve() {
  int next;
  if (n == 1) {
    puts("not unique");
    return;
  }
  int i, j, k;
  lo = 0;
  hi = 10.0;
  int m = 0;
  for (i = 1; i < n; ++i) {
    int t = a[i] - a[i - 1] - a[0];
    m += t;
    lo = (lo > (double)m * 10.0 / (i + 1) ? lo : (double)m * 10.0 / (i + 1));
    hi = (hi < (double)(m + 1) * 10.0 / (i + 1)
              ? hi
              : (double)(m + 1) * 10.0 / (i + 1));
  }
  int num = n + 1;
  double lf = lo * num - 10.0 * m;
  double ri = hi * num - 10.0 * m;
  if (lf < 10.0 && ri > 10.0) {
    puts("not unique");
    return;
  } else {
    next = a[n - 1] + a[1] - a[0];
    if (lf >= 10.0) ++next;
  }
  puts("unique");
  printf("%d\n", next);
}
int main() {
  int i, j, cas = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", &a[i]);
  solve();
  return 0;
}
