#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    bool ok = true;
    for (int j = 0; j < (n); j++) {
      int x;
      cin >> x;
      if (x == 1 || x == 3) ok = false;
    }
    if (ok) ans.push_back(i + 1);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (ans.size()); i++)
    cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
  return 0;
}
