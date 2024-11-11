#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  multiset<int> unused, plus;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = p[i];
    if (unused.size() && *unused.begin() < cur) {
      int a = *unused.begin();
      if (plus.size() && *plus.begin() < a) {
      } else {
        ans += cur - a;
        unused.erase(unused.begin());
        plus.insert(cur);
        continue;
      }
    }
    if (plus.size() && *plus.begin() < cur) {
      int a = *plus.begin();
      ans += cur - a;
      plus.erase(plus.begin());
      unused.insert(a);
      plus.insert(cur);
      continue;
    }
    unused.insert(cur);
  }
  cout << ans;
}
