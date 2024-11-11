#include <bits/stdc++.h>
using namespace std;
long n;
long x;
long a[100001];
long br[1000001];
long long s;
int main() {
  scanf("%ld %ld", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  for (int i = 0; i <= 1000000; i++) {
    br[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    br[a[i]]++;
  }
  s = 0;
  for (int i = 0; i < n; i++) {
    long p = a[i] ^ x;
    if (p != a[i])
      s += br[p];
    else
      s += br[p] - 1;
  }
  s /= 2;
  printf("%lld", s);
}
