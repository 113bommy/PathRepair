#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  for (long long i = 2; i <= n; ++i)
    if (n % (i * i) == 0) n /= i;
  cout << n;
  return 0;
}
