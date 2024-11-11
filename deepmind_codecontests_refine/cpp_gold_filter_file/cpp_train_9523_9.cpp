#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long m;
  cin >> n >> m;
  vector<int> r(n);
  int i, j;
  i = 0;
  j = n - 1;
  int cur = 1;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long pw = 1ll << (n - 2ll);
  m--;
  while (cur <= n) {
    if (pw <= m) {
      r[j] = cur;
      j--;
      m -= pw;
    } else {
      r[i] = cur;
      i++;
    }
    pw /= 2;
    cur++;
  }
  for (int i = 0; i < n; i++) cout << r[i] << " ";
}
