#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, i, a, t, sum = 0, sum1 = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    t = ((sum / m) - sum1);
    cout << t << " ";
    sum1 = t;
  }
  return 0;
}
