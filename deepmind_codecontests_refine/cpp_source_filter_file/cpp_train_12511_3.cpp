#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long p = 8 * n + 9 + 8 * k;
  p = sqrt(p);
  long long q = 2 * n + 3;
  long long s = (q - p) / 2;
  long long s2 = (p + q) / 2;
  if (s >= 0 && s < n) {
    cout << s;
  } else
    cout << s2;
  return 0;
}
