#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long prod = 1;
  for (int i = 1; i < n; i++) prod *= i;
  prod /= n;
  prod *= 2;
  cout << prod << endl;
  return 0;
}
