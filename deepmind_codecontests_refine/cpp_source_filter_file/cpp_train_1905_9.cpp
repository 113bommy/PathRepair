#include <bits/stdc++.h>
using namespace std;
long long n, m, luck[1200];
map<long long, vector<long long> > u;
long long a[120000];
bool ok(long long t) {
  while (t != 0) {
    if (t % 10 != 7 && t % 10 != 4) return false;
    t /= 10;
  }
  return true;
}
int main() {
  scanf("%I64d", &n);
  m = 0;
  long long t[4];
  t[1] = n + 2;
  t[2] = n + 1;
  t[3] = n;
  t[4] = n - 1;
  int c2 = 3, c3 = 1;
  for (int i = 1; i <= 4; i++) {
    while (t[i] % 2 == 0 && c2 > 0) t[i] /= 2, c2--;
    while (t[i] % 3 == 0 && c3 > 0) t[i] /= 3, c3--;
  }
  long long ans = t[1] * t[2] * t[3] * t[4];
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    if (ok(a[i])) {
      luck[++m] = i;
      u[a[i]].push_back(i);
    }
  }
  luck[0] = 0;
  for (long long i = 1; i <= m - 1; i++) {
    set<long long> check, seq;
    seq.insert(n + 1);
    seq.insert(luck[i]);
    long long sum = 0;
    for (long long j = i; j >= 1; j--) {
      if (check.count(a[luck[j]]) == 0) {
        long long tmp = a[luck[j]];
        check.insert(tmp);
        for (long long k = 0; k < u[tmp].size(); k++)
          if (u[tmp][k] > luck[i]) {
            set<long long>::iterator d = seq.insert(u[tmp][k]).first;
            set<long long>::iterator t1 = d, t2 = d;
            t1--;
            t2++;
            if (t1 != seq.begin()) {
              sum += (*t2 - *d) * (*d - *t1) * (luck[i + 1] - luck[i]);
            } else {
              sum += (*t2 - *d) * (*d - luck[i + 1]) * (luck[i + 1] - luck[i]);
              sum += (*t2 - *d) * (luck[i + 1] - luck[i] + 1) *
                     (luck[i + 1] - luck[i]) / 2;
            }
          }
      }
      ans -= (luck[j] - luck[j - 1]) * sum;
    }
  }
  cout << ans << endl;
  return 0;
}
