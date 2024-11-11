#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> l, r;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    l.push_back(x);
    r.push_back(y);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  long long res = n;
  for (long long i = 0; i < n; i++) res += max(l[i], r[i]);
  cout << res << endl;
  return 0;
}
