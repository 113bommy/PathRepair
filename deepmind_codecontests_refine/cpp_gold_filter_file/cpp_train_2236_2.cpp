#include <bits/stdc++.h>
using namespace std;
int n, k;
multiset<long long> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  long long x, y;
  for (int(i) = 0; (i) < (n); i++) {
    cin >> x >> y;
    if (s.size() < k) {
      s.insert(x + y);
      cout << x + y << '\n';
    } else {
      long long t = max(x, *s.begin());
      s.erase(s.begin());
      s.insert(t + y);
      cout << t + y << '\n';
    }
  }
  return 0;
}
