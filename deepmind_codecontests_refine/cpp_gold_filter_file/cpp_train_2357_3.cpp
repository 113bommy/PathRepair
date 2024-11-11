#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, m = 6;
  cin >> n >> a >> b;
  int q = n / a;
  for (int i = 1; (i <= 2) && (b * i <= n); i++)
    m = min((i ^ 3) + (4 - ((n - b * i) / a) * (i ^ 3) + q - 1) / q, m);
  cout << m;
}
