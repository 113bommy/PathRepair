#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool flag[46010];
void Sieve() {
  for (int i = 2; i <= 46000; i++) {
    if (!flag[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= 46000; j += i) flag[j] = 1;
    }
  }
}
int main() {
  Sieve();
  int N, M;
  scanf("%d", &N);
  M = (N * (N + 1)) >> 1;
  for (int i = 0; primes[i] * primes[i] <= M; i++) {
    if (M % primes[i] == 0) {
      puts("Yes");
      printf("1 %d\n", primes[i]);
      printf("%d", N - 1);
      for (int j = 1; j <= N; j++) {
        if (j == primes[i])
          continue;
        else
          printf(" %d", j);
      }
      puts("");
      return 0;
    }
  }
  puts("No");
  return 0;
}
