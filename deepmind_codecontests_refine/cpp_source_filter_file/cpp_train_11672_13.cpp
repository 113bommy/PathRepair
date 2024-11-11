#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, m, k, l;
  cin >> n >> m >> k >> l;
  unsigned long long int d = n / m;
  unsigned long long int e = (m + k + l) / m;
  if (e > d) {
    cout << -1;
  } else {
    cout << e;
  }
  return 0;
}
