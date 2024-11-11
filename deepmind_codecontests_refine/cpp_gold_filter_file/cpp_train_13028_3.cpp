#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ones = 0, twos = 0;
  for (int i = 0; i < (n); i++) {
    int x;
    cin >> x;
    if (x == 1)
      ones++;
    else
      twos++;
  }
  vector<int> ans;
  if (!ones) {
    while (twos--) cout << "2 ";
    cout << '\n';
    return 0;
  } else if (!twos) {
    while (ones--) cout << "1 ";
    cout << '\n';
    return 0;
  } else {
    ones--, twos--;
    ans.push_back(2);
    ans.push_back(1);
    while (twos--) ans.push_back(2);
    while (ones--) ans.push_back(1);
  }
  for (int i = 0; i < (ans.size()); i++) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}
