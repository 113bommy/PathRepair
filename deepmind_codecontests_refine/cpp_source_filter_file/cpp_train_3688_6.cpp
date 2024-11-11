#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e5 + 7;
const long long INF = 2e18 + 7;
long long n, a, b, d[MXN], sum = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> d[i];
  }
  cin >> a >> b;
  for (int i = 1; i <= b - 1; i++) {
    sum += d[i];
  }
  cout << sum;
  return 0;
}
