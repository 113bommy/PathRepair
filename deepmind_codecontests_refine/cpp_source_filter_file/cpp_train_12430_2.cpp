#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int main() {
  long long n;
  cin >> n;
  long long p = 1;
  while (n % p == 0) p *= 3;
  cout << n / 3 + 1 << endl;
  return 0;
}
