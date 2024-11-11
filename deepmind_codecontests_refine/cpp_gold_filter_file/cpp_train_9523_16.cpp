#include <bits/stdc++.h>
using namespace std;
const string problemName = "";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
const int INF = (1LL << 31) - 1;
const long long int LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MOD = (int)(1e9) + 7;
const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;
long long int N, M, j;
void solve(long long int i, long long int j) {
  if (i <= 1) {
    if (!((j & 3) ^ 0))
      printf("%lld %lld %lld ", N - 2, N - 1, N);
    else if (!((j & 3) ^ 1))
      printf("%lld %lld %lld ", N - 2, N, N - 1);
    else if (!((j & 3) ^ 2))
      printf("%lld %lld %lld ", N - 1, N, N - 2);
    else
      printf("%lld %lld %lld ", N, N - 1, N - 2);
    return;
  }
  if (j & (1LL << i)) {
    solve(i - 1, j - (1LL << i));
    printf("%lld ", N - i - 1);
  } else {
    printf("%lld ", N - i - 1);
    solve(i - 1, j - (1LL << i));
  }
}
int main() {
  scanf("%lld%lld", &N, &M);
  M--;
  if (N >= 3)
    solve(N - 2, M);
  else {
    if (N == 1)
      printf("1 ");
    else if (N == 2 && M == 0)
      printf("1 2 ");
    else
      printf("2 1 ");
  }
  return 0;
}
