#include <bits/stdc++.h>
using namespace std;
bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n;
  vector<int> ans;
  cin >> n;
  for (int i = 2; i < n; ++i) {
    if (prime(i)) {
      for (int j = i; j <= n; j *= i) {
        ans.push_back(j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}
