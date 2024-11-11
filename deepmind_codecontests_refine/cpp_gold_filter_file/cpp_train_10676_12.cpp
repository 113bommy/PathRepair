#include <bits/stdc++.h>
using namespace std;
long long i, j, n, k, l, m, x, y, tot, flag, h, r, ans, koko;
long long a[1000500];
string s;
int main() {
  cin >> n;
  k = 2;
  for (i = 1; i <= n; i++) {
    cout << i * (i + 1) * (i + 1) - k / i << endl;
    k = i * (i + 1);
  }
  return 0;
}
