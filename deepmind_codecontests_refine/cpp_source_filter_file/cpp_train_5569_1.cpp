#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t[51];
  t[0] = 1;
  t[1] = 1;
  for (int i = 2; i <= 50; ++i) {
    t[i] = t[i - 1] + t[i - 2];
  }
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    if (t[n - i] >= k) {
      cout << i;
    } else {
      k -= t[n - i];
      cout << i + 1 << ' ' << i;
      ++i;
    }
    if (i < n) {
      cout << ' ';
    }
  }
  cout << endl;
}
