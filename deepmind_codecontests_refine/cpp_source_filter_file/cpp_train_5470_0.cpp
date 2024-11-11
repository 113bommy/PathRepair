#include <bits/stdc++.h>
using namespace std;
int n, data[1005];
int gcd(int i, int j) {
  if (j == 0) return i;
  return gcd(j, i % j);
}
vector<int> ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> data[i];
  ans.push_back(data[1]);
  for (int i = 2; i <= n; i++) {
    int t = gcd(data[i], data[i - 1]);
    if (t != 1) {
      for (int x = 2;; x++)
        if (gcd(x, data[i]) == 1 && gcd(x, data[i - 1] == 1)) {
          ans.push_back(x);
          break;
        }
    }
    ans.push_back(data[i]);
  }
  cout << ans.size() - n << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
