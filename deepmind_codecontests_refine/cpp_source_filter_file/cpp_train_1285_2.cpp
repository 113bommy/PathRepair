#include <bits/stdc++.h>
using namespace std;
int k, b, n;
long long t;
int main(void) {
  cin >> k >> b >> n >> t;
  long long Z = 1;
  for (; Z < t; n--) Z = Z * k + b;
  cout << max(n + 1, 0);
  return 0;
}
