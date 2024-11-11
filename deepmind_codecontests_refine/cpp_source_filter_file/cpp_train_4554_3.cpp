#include <bits/stdc++.h>
using namespace std;
long long int n, a[101], sum;
bool chk() {
  double x = ((double)sum * 1000.00) / n;
  return (x >= 4445.00);
}
int main() {
  scanf("%lld", &n);
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a, a + n);
  long long int i = 0;
  while (true) {
    if (chk()) {
      cout << i << endl;
      return 0;
    }
    sum -= a[i++];
    sum += 5;
  }
}
