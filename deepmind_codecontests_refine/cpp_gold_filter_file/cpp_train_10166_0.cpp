#include <bits/stdc++.h>
using namespace std;
long long su[100000], cnt;
bool isprime[100000];
long long p, y;
void prime() {
  cnt = 1;
  memset(isprime, 1, sizeof(isprime));
  isprime[0] = isprime[1] = 0;
  for (long long i = 2; i <= 100000; i++) {
    if (isprime[i]) su[cnt++] = i;
    for (long long j = 1; j < cnt && su[j] * i < 100000; j++) {
      isprime[su[j] * i] = 0;
    }
  }
}
int main() {
  long long i, j;
  scanf("%I64d%I64d", &p, &y);
  prime();
  long long n = y;
  while (n > p) {
    int flag = 1;
    for (i = 1; i < cnt && su[i] <= p; i++) {
      if (n % su[i] == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
    n--;
  }
  if (n <= p)
    printf("-1\n");
  else
    printf("%I64d\n", n);
  return 0;
}
