#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &k);
    printf("%d\n", n % k ? n - n % k + min(k / 2, n % k) : n);
  }
  return 0;
}
