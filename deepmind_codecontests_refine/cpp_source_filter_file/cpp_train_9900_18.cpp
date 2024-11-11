#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main() {
  long long n, k, t;
  cin >> k >> n;
  if (n & 1)
    t = (n + 1) / 2;
  else
    t = n / 2;
  cout << max(0ll, min(k, n - 1) - t + 1) << endl;
  return 0;
}
