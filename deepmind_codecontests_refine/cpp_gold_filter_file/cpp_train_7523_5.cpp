#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<long long> s = {0};
  long long sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    sum += foo;
    if (s.count(sum)) {
      ans += 1;
      s.clear();
      sum = foo;
      s.insert(0);
    }
    s.insert(sum);
  }
  cout << ans << '\n';
  return 0;
}
