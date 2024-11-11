#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, m;
  cin >> n >> m;
  unsigned long long int d = 1, k;
  if (n <= 60) {
    for (int i = 0; i < n; i++) {
      d = d * 2;
    }
    k = m % d;
    cout << k;
  } else {
    cout << m;
  }
  return 0;
}
