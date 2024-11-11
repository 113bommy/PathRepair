#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int x = n;
  vector<int> ans;
  int count = 0;
  bool end = false;
  for (int i = 2; i < n; i++) {
    while (x % i == 0 && x / i != 1) {
      count++;
      ans.push_back(i);
      x /= i;
      if (count == k - 1) {
        end = true;
        break;
      }
    }
    if (end == true) break;
  }
  ans.push_back(x);
  if (k == 1)
    cout << n;
  else if (ans.size() < k)
    cout << -1;
  else {
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
