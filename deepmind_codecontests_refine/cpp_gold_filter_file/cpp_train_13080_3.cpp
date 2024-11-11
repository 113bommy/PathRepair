#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int n, s, f;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
  }
  scanf("%d %d", &s, &f);
  int start = -1, people = 0;
  for (int i = 1; i <= n; i++) {
    int S = s - i + 1, F = f - i + 1;
    if (S < 1) S += n;
    if (F < 1) F += n;
    long long p = 0;
    if (S < F)
      p = a[F - 1] - a[S - 1];
    else
      p = a[n] - a[S - 1] + a[F - 1];
    if (start == -1 || p > people) {
      start = i;
      people = p;
    }
  }
  printf("%d\n", start);
  return 0;
}
