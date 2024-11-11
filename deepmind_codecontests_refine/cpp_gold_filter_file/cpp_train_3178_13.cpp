#include <bits/stdc++.h>
using namespace std;
long long n, b, p;
int main() {
  cin >> n >> b >> p;
  cout << ((n - 1) * b * 2) + (n - 1) << " " << (n * p);
  return 0;
}
