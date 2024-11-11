#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const double pi = acos(-1.0);
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
inline int to_i(const string& s) {
  int n;
  sscanf(s.c_str(), "%d", &n);
  return n;
}
inline string to_s(int n) {
  char buf[32];
  sprintf(buf, "%d", n);
  return string(buf);
}
inline int rd() {
  int x;
  scanf("%d", &x);
  return x;
}
int n, m, h;
int a[10300];
int main() {
  int i, j, k;
  while (scanf("%d%d%d", &n, &m, &h) != EOF) {
    int sum = 0, all = 0;
    double ans = 0;
    for (i = 1; i <= m; i++) {
      a[i] = rd();
      sum += a[i];
      if (i != h) all += a[i];
    }
    if (n > sum) {
      ans = -1;
    } else if (n == 1) {
      ans = 0;
    } else if (m == 1) {
      ans = 1;
    } else if (n - 1 > all) {
      ans = 1;
    } else {
      int now = n - 1;
      sum--;
      j = all;
      k = sum;
      ans = 1;
      for (i = now; i > 0; i--) {
        ans *= (double)j / k;
        j--;
        k--;
      }
      ans = 1 - ans;
    }
    printf("%.6lf\n", ans + (1e-12));
  }
}
