#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long prod = 1;
  for (int i = 1; i < n; i++) prod *= i;
  prod *= 2;
  prod /= n;
  cout << prod << endl;
  return 0;
}
