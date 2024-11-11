#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
int las[100001];
int main() {
  int i, j;
  int n, sum = 0;
  cin >> n;
  for (j = 0; j < n; j++) {
    int x, ans = 0;
    cin >> x;
    while (x) {
      if (x % 2) ans++;
      x /= 2;
    }
    las[ans]++;
    sum += (las[ans] - 1);
  }
  cout << sum;
  return 0;
}
