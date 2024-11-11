#include <bits/stdc++.h>
using namespace std;
int sz;
pair<long long, int> a[20];
int b[20];
long long st[20][70];
long long fr1, fr2;
const long double eps = 1e-10;
long long v1;
long long a1, b1, c;
long long ans;
long long help;
void calc1(int v, long long kol) {
  if (2 * kol * help + 2 * kol + 2 * help > ans) return;
  if (v == sz) {
    long long k = v1 / (help * kol);
    if (ans > 2 * (help * kol + kol * k + help * k)) {
      a1 = help;
      b1 = kol;
      c = k;
      ans = 2 * (a1 * b1 + b1 * c + c * a1);
    }
    return;
  }
  for (int i = b[v]; i >= 0; i--)
    if (kol * st[v][i] <= fr2) calc1(v + 1, kol * st[v][i]);
}
void calc(int v, long long kol) {
  if (v == sz) {
    help = kol;
    fr2 = (long long)(sqrt(1.0 * v1 / (1.0 * kol)) + eps);
    long double help1 = sqrt(1.0 * v1 / (1.0 * kol));
    if (2 * (2 * kol * help1 + help1 * help1) - ans > -eps) return;
    calc1(0, 1);
    return;
  }
  b[v] = 0;
  for (int i = a[v].second; i >= 0; i--) {
    if (st[v][i] * kol <= fr1) calc(v + 1, kol * st[v][i]);
    b[v]++;
  }
}
inline void print() {
  cout << ans << ' ' << a1 << ' ' << b1 << ' ' << c << endl;
}
int main() {
  int t;
  cin >> t;
  for (int qqq = 0; qqq < int(t); qqq++) {
    scanf("%d", &sz);
    v1 = 1;
    for (int i = 0; i < int(sz); i++) {
      cin >> a[i].first >> a[i].second;
      st[i][0] = 1;
      for (int j = 0; j < int(a[i].second); j++) {
        v1 *= a[i].first;
        st[i][j + 1] = st[i][j] * a[i].first;
      }
    }
    a1 = b1 = 1;
    c = v1;
    ans = 2 * (a1 * b1 + b1 * c + c * a1);
    fr1 = (long long)(exp(log(1.0 * v1) / 3.0) + eps);
    calc(0, 1);
    print();
  }
  return 0;
}
