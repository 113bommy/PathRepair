#include <bits/stdc++.h>
using namespace std;
int flag = 0, u = 1000000007;
int main() {
  long long int n, m, q = 1, a = 1, i;
  cin >> n >> m;
  q = 1;
  for (i = 0; i < m; i++) {
    q = (q * 2) % u;
  }
  for (i = 0; i < n; i++) {
    q = (q - 1) % u;
    a = (a * q) % u;
  }
  cout << a;
}
