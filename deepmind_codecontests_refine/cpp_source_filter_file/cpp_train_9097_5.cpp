#include <bits/stdc++.h>
using namespace std;
long long n;
long long k = 1LL;
int main() {
  cin >> n;
  while (n % k == 0) k = k * 3;
  cout << n / 3 + 1 << endl;
  return 0;
}
