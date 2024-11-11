#include <bits/stdc++.h>
using namespace std;
int k[3];
long long t[200000];
long long c[200000];
int n;
long long T[3];
long long nt[200000];
multiset<long long> s;
int main(void) {
  for (int i = 0; i < 3; i++) scanf(" %d", &k[i]);
  for (int i = 0; i < 3; i++) scanf(" %I64d", &T[i]);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &c[i]), nt[i] = c[i];
  for (int i = 0; i < 3; i++) k[i] = min(k[i], n + 1);
  for (int step = 0; step < 3; step++) {
    s.clear();
    for (int i = 0; i < k[step]; i++) {
      s.insert(0ll);
    }
    for (int i = 0; i < n; i++) t[i] = nt[i];
    for (int i = 0; i < n; i++) {
      long long TM = max(*s.begin(), t[i]);
      nt[i] = TM + T[step];
      s.erase(s.begin());
      s.insert(nt[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, nt[i] - c[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
