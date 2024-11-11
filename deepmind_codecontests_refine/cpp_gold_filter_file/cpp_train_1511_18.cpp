#include <bits/stdc++.h>
using namespace std;
long long a[10000100];
int main() {
  long long n;
  scanf("%I64d", &n);
  long long y;
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &y);
    a[y]++;
  }
  for (long long i = 0; i <= 10000000; i++) {
    a[i + 1] += a[i] / 2;
    a[i] = a[i] % 2;
  }
  long long cnt = 0;
  for (long long i = 0; i <= 10000000; i++) {
    if (a[i] > 0) {
      cnt++;
    }
  }
  printf("%I64d", cnt);
}
