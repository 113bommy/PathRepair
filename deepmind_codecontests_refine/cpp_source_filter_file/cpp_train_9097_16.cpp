#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int c = 3;
  while (n % c == 0) c *= 3;
  cout << n / c + 1 << '\n';
  return 0;
}
