#include <bits/stdc++.h>
using namespace std;
long long A[200005], B[200005];
int Update[200005], X[200005];
int main() {
  int N, i;
  long long t;
  scanf("%d%lld", &N, &t);
  for (i = 1; i <= N; ++i) scanf("%lld", A + i);
  for (i = 1; i <= N; ++i) {
    scanf("%d", X + i);
    if (X[i] < X[i - 1] || X[i] < i) {
      puts("No");
      return 0;
    }
    Update[i] += 1;
    Update[X[i]] -= 1;
  }
  for (i = 1; i <= N; ++i) {
    Update[i] += Update[i - 1];
    if (Update[i] > 0)
      B[i] = A[i + 1] + t;
    else
      B[i] = A[i] + t;
  }
  for (i = 1; i <= N; ++i) {
    if (B[i] <= B[i - 1]) B[i] = B[i - 1] + 1;
  }
  A[N + 1] = 2 * 1000000LL * 1000000LL * 1000000LL;
  for (i = 1; i < N; ++i) {
    if (X[i] > i && B[i] >= A[X[i] + 1] + t) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (i = 1; i <= N; ++i) printf("%lld ", B[i]);
  puts("");
  return 0;
}
