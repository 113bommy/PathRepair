#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int i = 1; i <= 72; i++) {
    int p = n - i, s = 0;
    while (p) {
      s += (p % 10);
      p /= 10;
    }
    if (s == i) {
      ans.push_back(n - i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
