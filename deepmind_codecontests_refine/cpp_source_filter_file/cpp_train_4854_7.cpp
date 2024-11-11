#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val;
  cin >> n;
  multiset<int> priority;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    if (!priority.empty() && *priority.begin() < val) {
      ans += *priority.begin();
      priority.erase(priority.begin());
      priority.insert(val);
    }
    priority.insert(val);
  }
  cout << ans << "\n";
  return 0;
}
