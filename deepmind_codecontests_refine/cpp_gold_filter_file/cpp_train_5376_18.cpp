#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if ((long double)((long double)log(m) / (long double)log(2)) >= (n - 0.1)) {
    cout << m % (1 << n);
  } else {
    cout << (m);
  }
  return 0;
}
