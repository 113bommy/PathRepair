#include <bits/stdc++.h>
using namespace std;
int lowbit(int n) { return n & (-n); }
int main() {
  int sum, limit;
  cin >> sum >> limit;
  vector<int> ans;
  for (int i = limit; i >= 1; i--) {
    int k = lowbit(i);
    if (sum >= i) {
      sum -= i;
      ans.push_back(i);
    }
    if (sum <= 0) break;
  }
  if (sum > 0) {
    cout << "-1";
    return 0;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
