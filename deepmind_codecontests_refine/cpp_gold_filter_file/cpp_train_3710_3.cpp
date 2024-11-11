#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h1, a1, c1, h2, a2;
  vector<string> ans;
  cin >> h1 >> a1 >> c1 >> h2 >> a2;
  while (h2 > 0) {
    if (h1 <= a2 && a1 < h2) {
      ans.push_back("HEAL");
      h1 += c1;
    } else {
      ans.push_back("STRIKE");
      h2 -= a1;
    }
    h1 -= a2;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
