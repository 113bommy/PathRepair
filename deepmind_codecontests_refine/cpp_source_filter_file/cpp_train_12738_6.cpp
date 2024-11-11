#include <bits/stdc++.h>
using namespace std;
const long long maxn = (long long)5e5;
const long long linf = (long long)1e16;
const long long mod = (long long)1e9 + 7;
long long n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    if (i % 2)
      cout << i + 1 << " ";
    else
      cout << i - 1 << " ";
  }
  return 0;
}
