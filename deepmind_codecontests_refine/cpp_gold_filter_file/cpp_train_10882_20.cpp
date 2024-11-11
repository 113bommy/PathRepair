#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, temp;
  cin >> n >> m;
  set<long long int> s;
  vector<long long int> ans;
  for (long long int i = 0; i < n; i++) {
    cin >> temp;
    s.insert(temp);
  }
  long long int m1 = m;
  for (long long int i = 1; i < m1 + 1; i++) {
    if (s.find(i) == s.end()) {
      if (m >= i) {
        ans.push_back(i);
        m = m - i;
      } else {
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
