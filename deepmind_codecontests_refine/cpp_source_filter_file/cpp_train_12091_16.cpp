#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, M, K, ar[200005];
  scanf("%lld %lld %lld", &N, &M, &K);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &ar[i]);
  }
  sort(ar, ar + N);
  long long a = ar[N - 1], b = ar[N - 2];
  long long ans = (((K * a + b) * (M / (K + 1))) + ((M % (K + 1)) * a));
  printf("%lld\n", ans);
  return 0;
}
