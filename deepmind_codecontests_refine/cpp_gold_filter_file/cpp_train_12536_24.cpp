#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
using namespace std;
vector<int> l, r;
vector<int>::iterator it;
int main() {
  int n, m, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0)
      l.push_back(i);
    else
      r.push_back(i);
  }
  reverse(r.begin(), r.end());
  long long ans = 0;
  while (!r.empty()) {
    it = lower_bound(l.begin(), l.end(), r.back());
    int id = it - l.begin();
    ans += (l.size() - id);
    r.pop_back();
  }
  cout << ans << endl;
  return 0;
}
