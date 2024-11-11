#include <bits/stdc++.h>
using namespace std;
int main() {
  long t, n, i, j;
  long long x;
  cin >> n >> x;
  for (i = 1; i <= n; i++)
    if (x / i == (x * 1.00 / i) && (x / i) <= n) t++;
  cout << t;
}
