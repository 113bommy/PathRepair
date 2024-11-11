#include <bits/stdc++.h>
using namespace std;
const int NMax = 110000;
const long long INF = 1000000007LL;
int N1, N2, nn;
long long F[1000010];
int main() {
  scanf("%d", &nn);
  for (int i = 1; i <= nn; i++) {
    int first;
    scanf("%d", &first);
    if (first == 1)
      N1++;
    else
      N2++;
  }
  long long ret = 1;
  for (int i = N1 + 1; i <= N1 + N2; i++) ret = ret * (long long)i % INF;
  F[1] = 1;
  F[2] = 2;
  for (int i = 3; i <= N1; i++)
    F[i] = (F[i - 2] + (long long)(i - 1) * F[i - 1] % INF) % INF;
  ret = ret * F[N1] % INF;
  printf("%lld\n", ret);
  return 0;
}
