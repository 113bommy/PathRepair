#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, s;
  cin >> n >> m >> s;
  cout << (((n % s == 0) ? n : (n % s) * ((n / s) + 1)) *
           ((m % s == 0) ? m : (m % s) * ((m / s) + 1)));
  return 0;
}
