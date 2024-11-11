#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long a = n / i;
      ans.push_back((a * (2 + (a - 1) * i)) / 2);
      a = i;
      if (i * i != n) ans.push_back((a * (2 + (a - 1) * (n / i)) / 2));
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
