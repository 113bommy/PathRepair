#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  multiset<long long> m;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    if (!m.empty() && *m.begin() < x) {
      ans += x - *m.begin();
      m.erase(m.begin());
      m.insert(x);
      m.insert(x);
    } else {
      m.insert(x);
    }
  }
  cout << ans << endl;
}
