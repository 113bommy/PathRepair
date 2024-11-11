#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 9;
int main() {
  int n, m;
  long double sum = 0;
  long long dist1 = 0, dist2 = 0;
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) dist1 += i;
  if (n % 2)
    for (int i = 1; i <= n / 2; i++) dist2 += i + i;
  else {
    int i;
    for (i = 1; i <= n / 2; i++) dist2 += i + i;
    dist2 -= i - 1;
  }
  for (int i = 0; i < int(m); i++) {
    int x, d;
    cin >> x >> d;
    if (d > 0)
      sum = sum + d * dist1 + n * x;
    else
      sum = sum + d * dist2 + n * x;
  }
  cout << fixed << setprecision(10);
  cout << sum / n;
  return 0;
}
