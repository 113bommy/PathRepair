#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  n = (n * (n - 1)) / 2 + (((n * (n - 1)) / 2) * ((2 * n - 1))) / 3 - 2;
  cout << n << endl;
  return 0;
}
