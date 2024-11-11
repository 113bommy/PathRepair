#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, b, t, d;
  cin >> n >> b;
  long long int j = 0, ft = 0;
  vector<long long int> v;
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    cin >> t >> d;
    if (s.empty()) {
      s.insert(t + d);
      cout << t + d << " ";
      continue;
    }
    set<long long int>::iterator it = s.begin();
    while (*it <= t && !s.empty()) {
      s.erase(it);
      it = s.begin();
    }
    if (s.size() <= b) {
      long long int now;
      if (s.empty())
        now = t + d;
      else
        now = *s.begin() + d;
      s.insert(now);
      cout << *s.rbegin() << " ";
    } else {
      cout << -1 << " ";
    }
  }
}
