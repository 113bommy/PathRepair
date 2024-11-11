#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int main() {
  long long int n, i, j, jump;
  scanf("%lld", &n);
  vector<long long int> vetor(n);
  set<long long int> numbers;
  set<long long int>::iterator it, ita;
  for (i = 0; i < n; i++) {
    scanf("%lld", &vetor[i]);
    numbers.insert(vetor[i]);
  }
  bool foi;
  for (i = 0; i < n; i++) {
    if (numbers.find(vetor[i] - 1) != numbers.end() and
        numbers.find(vetor[i] + 1) != numbers.end()) {
      printf("3\n");
      printf("%lld %lld %lld\n", vetor[i], vetor[i] - 1, vetor[i] + 1);
      return 0;
    }
    foi = false;
    for (j = 0; j < 30 and !foi; j++) {
      jump = 2 << j;
      it = numbers.find((long long int)vetor[i] - jump);
      ita = numbers.find((long long int)vetor[i] + jump);
      if (it != numbers.end() and ita != numbers.end()) {
        printf("3\n");
        printf("%lld %lld %lld\n", vetor[i], *it, *ita);
        return 0;
      }
      if (vetor[i] - jump < -1e9 + 7) foi = true;
      if (vetor[i] + jump > -1e9 + 7) foi = true;
    }
  }
  for (i = 0; i < n; i++) {
    if (numbers.find(vetor[i] - 1) != numbers.end()) {
      printf("2\n");
      printf("%lld %lld\n", vetor[i], vetor[i] - 1);
      return 0;
    }
    if (numbers.find(vetor[i] + 1) != numbers.end()) {
      printf("2\n");
      printf("%lld %lld\n", vetor[i], vetor[i] + 1);
      return 0;
    }
    foi = false;
    for (j = 0; j < 30; j++) {
      jump = 2 << j;
      it = numbers.find((long long int)vetor[i] - jump);
      ita = numbers.find((long long int)vetor[i] + jump);
      if (it != numbers.end()) {
        printf("2\n");
        printf("%lld %lld\n", vetor[i], *it);
        return 0;
      }
      if (ita != numbers.end()) {
        printf("2\n");
        printf("%lld %lld\n", vetor[i], *ita);
        return 0;
      }
      if (vetor[i] - jump < -1e9 + 7) foi = true;
      if (vetor[i] + jump > -1e9 + 7) foi = true;
    }
  }
  printf("1\n%lld\n", vetor[0]);
  return 0;
}
