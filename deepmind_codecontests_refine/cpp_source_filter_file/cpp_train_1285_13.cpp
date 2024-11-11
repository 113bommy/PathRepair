#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long a = k + b;
  while (a < t) a = k * a + b, n--;
  cout << (n < 0 ? 0 : n) << endl;
}
