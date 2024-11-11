#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, b, n, t, i, j;
  scanf("%lld", &k);
  ;
  scanf("%lld", &b);
  ;
  scanf("%lld", &n);
  ;
  scanf("%lld", &t);
  ;
  long long int prev = 1;
  for (i = 1;; i++) {
    long long int curr = k * prev + b;
    if (curr >= t) break;
    prev = curr;
  }
  cout << max(0LL, n - i + 1) << endl;
  return 0;
}
