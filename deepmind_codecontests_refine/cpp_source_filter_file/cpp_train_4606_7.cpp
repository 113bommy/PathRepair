#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long x;
  cin >> x;
  vector<long long> a;
  while (x > 0) {
    a.push_back(x % 2);
    x /= 2;
  }
  while (a.size() < 100) a.push_back(0);
  reverse(a.begin(), a.end());
  long long b[6];
  for (long long i = a.size() - 6; i < a.size(); ++i) {
    b[i - a.size() + 6] = a[i];
  }
  long long start = a.size() - 6;
  a[start + 0] = b[0];
  a[start + 1] = b[5];
  a[start + 2] = b[3];
  a[start + 3] = b[1];
  a[start + 4] = b[4];
  a[start + 5] = b[2];
  long long ans = 0;
  for (long long i = 0; i < a.size(); ++i) {
    ans = ans * 2 + a[i];
  }
  cout << ans;
  return 0;
}
