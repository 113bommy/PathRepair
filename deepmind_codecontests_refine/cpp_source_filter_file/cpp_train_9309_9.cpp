#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, l, r;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> l >> r;
    int k = n / l;
    long long tmp2 = (long long)k * r;
    long long tmp1 = (long long)k * l;
    if (tmp1 <= n && n <= tmp2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
