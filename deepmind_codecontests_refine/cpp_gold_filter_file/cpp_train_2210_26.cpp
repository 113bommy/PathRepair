#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  int x[21] = {};
  long long res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    x[t + 10]++;
  }
  for (int i = 0; i < 10; i++) {
    res += x[i] * 1ull * x[20 - i];
  }
  res += x[10] * 1ull * (x[10] - 1) / 2;
  cout << res << endl;
  return 0;
}
