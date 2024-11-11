#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b;
int main() {
  cin >> n >> m >> a >> b;
  int c = n % m;
  cout << min(c * b, (m - c) * a);
  return 0;
}
