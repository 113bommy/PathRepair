#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tcase = 1, cas = 0;
  while (tcase--) {
    vector<char> a, ans;
    for (int i = 1; i < 10; i++) ans.push_back(i + 48);
    for (int i = 10; i < 1000; i++) {
      int x = i;
      while (x) {
        a.push_back((x % 10) + 48);
        x /= 10;
      }
      reverse(a.begin(), a.end());
      for (int i = 0; i < a.size(); i++) {
        ans.push_back(a[i]);
      }
      a.clear();
    }
    int k;
    cin >> k;
    cout << ans[k - 1];
  }
  return 0;
}
