#include <bits/stdc++.h>
using namespace std;
struct ant {
  int s, d, i;
  bool operator<(const ant& a) const { return s < a.s; }
};
int n, m;
long long int t;
char tmp[10];
long long int mod(long long int a, long long int m) {
  a -= (a / m) * m;
  if (a < 0) return a + m;
  return a;
}
int main() {
  scanf("%d%d%lld", &n, &m, &t);
  vector<ant> a(n);
  vector<int> res(n), na(n);
  long long int cnt = 0, sum = 0, nm = (long long int)n * m;
  for (int i = 0; i < n; ++i) {
    scanf("%d%s", &a[i].s, tmp);
    a[i].s = mod(a[i].s, m);
    if (tmp[0] == 'L')
      a[i].d = -1;
    else
      a[i].d = 1;
    a[i].i = i;
    cnt = cnt + a[i].d;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) na[i] = mod(mod(t, m) * a[i].d + a[i].s, m);
  sort(na.begin(), na.end());
  if (cnt < 0)
    for (int i = 0; i < -cnt; ++i) sum = mod(sum + mod(-t, nm), nm);
  else
    for (int i = 0; i < cnt; ++i) sum = mod(sum + mod(t, n * m), nm);
  for (int i = 0; i < n; ++i) sum = mod(sum - (na[i] - a[i].s), nm);
  for (int i = 0; i < n; ++i) res[a[i].i] = na[mod(i + sum / m, n)];
  for (int i = 0; i < n; ++i) printf("%d ", (res[i] == 0) ? (m) : (res[i]));
  return 0;
}
