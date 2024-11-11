#include <bits/stdc++.h>
int f(long long n, long long l, long long r) {
  if (n < 2) {
    return n;
  }
  long long len = 0;
  long long k = n;
  while (k) {
    ++len;
    k >>= 1;
  }
  long long seq_len = (1LL << len) - 1;
  int ret = 0;
  long long mid = seq_len / 2 + 1;
  if (l <= mid && mid <= r) {
    ret += (n & 1);
  }
  if (l < mid) {
    if (r < mid) {
      ret += f(n >> 1, l, r);
    } else {
      ret += f(n >> 1, l, mid - 1);
    }
  }
  if (mid < r) {
    if (mid < l) {
      ret += f(n >> 1, l - mid, r - mid);
    } else {
      ret += f(n >> 1, 1, r - mid);
    }
  }
  return ret;
}
int main() {
  long long n, l, r;
  scanf("%lli%lli%lli", &n, &l, &r);
  printf("%d\n", f(n, l, r));
}
