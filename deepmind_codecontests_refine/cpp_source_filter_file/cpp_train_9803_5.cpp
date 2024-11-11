#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  long long n;
  scanf("%lld", &n);
  int flag = 0;
  int cnt = 0;
  for (long long i = 2; i <= n; i++) {
    flag = 0;
    for (long long j = 2; j * j <= i; j++) {
      if (n % i == 0) {
        flag = 1;
        a[i] = a[j];
        printf("%d ", a[i]);
        break;
      }
    }
    if (flag == 0) {
      a[i] = ++cnt;
      printf("%d ", a[i]);
    }
  }
}
