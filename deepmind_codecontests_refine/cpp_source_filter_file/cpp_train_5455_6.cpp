#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  cout << (((n % s == 0) ? n : (n % s) * ((n / s) + 1)) *
           ((m % s == 0) ? n : (m % s) * ((m / s) + 1)));
  return 0;
}
