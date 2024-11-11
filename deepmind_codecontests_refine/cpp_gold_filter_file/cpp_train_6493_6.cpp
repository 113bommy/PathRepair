#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) t += i * i - 1;
  n = (n * n * (n + 1)) / 2;
  cout << n - t;
  return 0;
}
