#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long i;
  scanf("%d", &n);
  long long m = 2;
  for (int k = 1; k <= n; k++) {
    long long x = 1LL * k * (k + 1) * (k + 1);
    cout << x - m << endl;
    m = x;
  }
  return 0;
}
