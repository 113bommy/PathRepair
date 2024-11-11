#include <bits/stdc++.h>
using namespace std;
long long mex(long long x, long long y) {
  long long res = 1;
  x = x;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long find(long long x, long long pika) {
  for (int i = pika; i >= 0; i--) {
    if (x & mex(2, (i - 1)) == 0) return i;
  }
}
int main() {
  long long n;
  scanf("%lli", &n);
  long long cnt = 0;
  long long arr[69];
  long long it = 0;
  while ((n & (n + 1)) != 0) {
    if (cnt % 2 == 1) {
      cnt++;
      n++;
      continue;
    }
    long long pika = log2(n);
    arr[it++] = pika;
    long long nig = mex(2, pika + 1) - 1;
    n ^= nig;
    cnt++;
  }
  printf("%lli\n", cnt);
  for (int i = 0; i < it; i++) {
    printf("%lli ", arr[i]);
  }
}
