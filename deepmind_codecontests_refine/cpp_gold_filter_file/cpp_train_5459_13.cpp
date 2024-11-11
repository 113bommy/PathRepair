#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (1LL << 20) + 10;
void fi(const char* tem) {
  if (!strlen(tem)) return;
  char A[50];
  const char B[4] = {'.', 'i', 'n', 0}, C[5] = {'.', 'o', 'u', 't', 0};
  memset(A, 0, sizeof(A));
  sprintf(A, "%s%s", tem, B);
  freopen(A, "r", stdin);
  sprintf(A, "%s%s", tem, C);
  freopen(A, "w", stdout);
  return;
}
long long N, M;
int main() {
  fi("");
  scanf("%lld", &N);
  printf("%lld\n", (N / 2) * (N - N / 2));
  for (long long i = 1; i <= N / 2; i++) {
    for (long long j = N / 2 + 1; j <= N; j++) {
      printf("%lld %lld\n", i, j);
    }
  }
  return 0;
}
