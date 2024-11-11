#include <bits/stdc++.h>
using namespace std;
int n, t;
int m[100010 * 2];
int main() {
  cin >> n;
  for (int i = 0; i < (n + 1) / 2; i++) {
    cin >> t;
    m[t - i + 100010]++;
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    cin >> t;
    m[t - i + 100010]++;
  }
  int mmax = 0;
  for (int i = 100010 + 1; i < 100010 * 2; i++) mmax = max(mmax, m[i]);
  cout << n - mmax;
  return 0;
}
