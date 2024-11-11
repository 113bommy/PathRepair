#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3000000;
int cnt[NMAX + 1];
long long Z[NMAX + 1];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    cnt[t]++;
  }
  for (int i = 1; i <= NMAX; i++) {
    for (int j = i; j <= NMAX; j += i) {
      int m = j / i;
      if (i != m)
        Z[j] += (long long)cnt[i] * cnt[m];
      else
        Z[j] += (long long)cnt[i] * (cnt[i] - 1) / 2;
    }
  }
  for (int i = 2; i <= NMAX; i++) Z[i] += Z[i - 1];
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int p;
    scanf("%d", &p);
    printf("%lld\n", (long long)n * (n - 1) - Z[p - 1]);
  }
}
