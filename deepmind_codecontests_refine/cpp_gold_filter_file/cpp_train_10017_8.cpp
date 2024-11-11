#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
    sum += i;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!((sum - ar[i]) & 1)) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
