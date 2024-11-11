#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long minRange = n;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    minRange = min(minRange, b - a + 1);
  }
  cout << minRange - 1 << endl;
  for (long long i = 0; i < n; i++) {
    cout << i % minRange << " ";
  }
  return 0;
}
