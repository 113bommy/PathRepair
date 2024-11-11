#include <bits/stdc++.h>
using namespace std;
int N, K;
int c0, c1, A;
int main() {
  scanf("%d%d", &N, &K);
  for (int(i) = 0; (i) < (N); (i)++)
    scanf("%d", &A), c0 += (A % 2 == 0), c1 += (A % 2 == 1);
  if (N == K) {
    if (c1 % 2)
      puts("Stannis");
    else
      puts("Daenerys");
  } else if ((N - K) % 2 == 0) {
    if (c0 <= (N - K) / 2 && (c1 - (N - K - c0)) % 2 == 1)
      puts("Stannis");
    else
      puts("Daenerys");
  } else {
    if (c1 <= (N - K) / 2 || (c0 <= (N - K) / 2 && K % 2 == 0))
      puts("Daenerys");
    else
      puts("Stannis");
  }
}
