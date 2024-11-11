#include <bits/stdc++.h>
using namespace std;
const int maxn = 1073741820;
int prime[1000001], pn, isprime[1000001];
int pow(int x, int y) {
  int sum = 1;
  for (int(i) = (1); (i) <= (y); (i)++) {
    sum *= x;
  }
  return sum;
}
int solve(int x) {
  int temp = x;
  int wei = 0;
  while (temp != 0) {
    temp /= 10;
    wei++;
  }
  int sum = 0;
  int cnt = pow(10, wei - 1);
  while (x != 0) {
    sum += cnt * (x % 10);
    cnt /= 10;
    x /= 10;
  }
  return sum;
}
void getPrime(int n) {
  int i, j;
  memset(isprime, 0, sizeof(isprime));
  pn = 0;
  isprime[1] = 1;
  for (i = 2; i <= n; i++) {
    if (!isprime[i]) prime[++pn] = i;
    for (j = 1; j <= pn && prime[j] * i <= n; j++) {
      isprime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int a[200000];
int main() {
  int n;
  n = 100;
  getPrime(n);
  int cnt = 1;
  for (int(i) = (1); (i) <= (pn); (i)++) {
    int dif = solve(prime[i]);
    if (prime[i] > 10 && (!isprime[dif]) && prime[i] != dif) {
      a[cnt++] = prime[i];
    }
  }
  scanf("%d", &(n));
  printf("%d", (a[n]));
  printf("\n");
  ;
}
