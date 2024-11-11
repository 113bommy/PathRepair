#include <bits/stdc++.h>
using namespace std;
long long n, b[500001], c, d, k, a[500001];
int main() {
  cin >> n >> k;
  multiset<long long> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (c < k) {
      c += 1;
      s.insert(a[i] + b[i]);
      d = a[i] + b[i];
    } else {
      if (*s.begin() > a[i]) {
        d = *s.begin() + b[i];
        s.erase(s.begin());
        s.insert(d);
      } else {
        d = a[i] + b[i];
        s.erase(s.begin());
        s.insert(d);
      }
    }
    cout << d << "\n";
  }
  return 0;
}
