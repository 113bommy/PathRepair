#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6;
int N;
long long K;
int A[Maxn + 5];
int main() {
  scanf("%d %lld", &N, &K);
  for (int i = 1; i <= N; i++) A[i] = i;
  long long ans = (N + 1) * N / 2;
  if (ans > K) {
    puts("-1");
    return 0;
  }
  int j = N;
  for (int i = 1; i <= N; i++)
    if (ans + j - i <= K && j > i) swap(A[i], A[j]), ans += j - i, j--;
  printf("%lld\n", ans);
  for (int i = 1; i <= N; i++) printf("%d ", i);
  puts("");
  for (int i = 1; i <= N; i++) printf("%d ", A[i]);
  return 0;
}
