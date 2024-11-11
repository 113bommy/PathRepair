#include <bits/stdc++.h>
using namespace std;
long long p10(long long n) {
  long long i = 1, j;
  for (j = 1; j <= n; j++) i *= 10;
  return i;
}
int main() {
  int n, sum = 0, d = 0, i;
  cin >> n;
  while (p10(d) <= n) d++;
  for (i = 1; i <= d; i++) {
    sum += n - p10(i - 1) + 1;
  }
  cout << sum;
  return 0;
}
