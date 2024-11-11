#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, k, a[N];
double b[N], v[N];
long long s[N];
double f[N][51];
struct line {
  long long a;
  double b;
  line(long long a = 0, double b = 0) : a(a), b(b) {}
};
bool bad(line l1, line l2, line l3) {
  return (double)(l1.b - l3.b) / (l3.a - l1.a) <
         (double)(l2.b - l1.b) / (l1.a - l2.a);
}
vector<line> L;
void add(line d) {
  while (L.size() >= 2 && bad(L[L.size() - 2], L[L.size() - 1], d))
    L.pop_back();
  L.push_back(d);
}
double F(int pos, double x) {
  if (pos == L.size())
    return 1e18;
  else
    return L[pos].a * x + L[pos].b;
}
double get(double x) {
  int l = 0, r = L.size();
  while (l < r) {
    int mid = ((l + r) >> 1);
    if (F(mid, x) <= F(mid + 1, x))
      r = mid;
    else
      l = mid + 1;
  }
  return F(l, x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; ++i)
    b[i] = b[i - 1] + (double)1.0 / a[i], v[i] = v[i - 1] + (double)s[i] / a[i];
  for (int i = 1; i <= k; ++i) f[0][i] = 1e18;
  for (int i = 1; i <= n; ++i) f[i][0] = 1e18;
  for (int t = 1; t <= k; ++t) {
    L.clear();
    L.push_back(line(0, f[0][t - 1]));
    for (int i = 1; i <= n; ++i) {
      f[i][t] = get(b[i]) + v[i];
      add(line(-s[i], f[i][t - 1] - v[i] + (double)s[i] * b[i]));
    }
  }
  cout << setprecision(4) << fixed << f[n][k] << endl;
}
