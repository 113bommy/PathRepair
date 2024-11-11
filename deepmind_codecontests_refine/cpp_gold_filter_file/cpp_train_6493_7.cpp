#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0, d = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    sum += i * (n - i + 1);
    d += i;
  }
  d -= n;
  sum -= d;
  cout << sum;
}
