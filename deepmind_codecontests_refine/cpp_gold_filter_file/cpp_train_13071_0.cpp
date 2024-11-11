#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
int N, M, A[MAXN], F[MAXN];
long long pre[MAXN];
bool used[MAXN];
long long ans;
int main() {
  scanf("%d", &N);
  memset(F, 0, sizeof(F));
  ans = M = 0;
  for (int i = 1; i <= N; i++) scanf("%d", A + i), F[A[i]]++, M = max(M, A[i]);
  if (F[1]) {
    for (int i = 1; i <= N; i++) ans += A[i];
    printf("%lld\n", ans);
    return 0;
  }
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= M; i++) {
    pre[i] = pre[i - 1] + F[i];
  }
  memset(used, false, sizeof(used));
  for (int i = 2; i <= M; i++) {
    if (used[i] || !F[i]) continue;
    long long temp = 0;
    for (int j = i; j <= M; j += i) {
      temp += (pre[j - 1] - pre[j - i - 1]) * (j - i);
      used[j] = true;
    }
    temp += (pre[M] - pre[(M / i) * i - 1]) * ((M / i) * i);
    ans = max(ans, temp);
  }
  printf("%lld\n", ans);
  return 0;
}
