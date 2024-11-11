#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
int main() {
  ios_base::sync_with_stdio(false);
  vector<int> ans;
  int n;
  cin >> n;
  while (n--) {
    ans.push_back(1);
    int index = ans.size() - 1;
    while (index > 0) {
      if (ans[index] == ans[index - 1]) {
        ++ans[index - 1];
        ans.pop_back();
        --index;
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " \n"[i == ans.size() - 1];
}
