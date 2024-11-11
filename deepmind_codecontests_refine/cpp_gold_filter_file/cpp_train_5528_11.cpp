#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string second;
  cin >> second;
  if (second.length() == 2) {
    if (second[0] != second[1]) {
      cout << 2 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  }
  while (second[0] != second[second.length() - 1]) {
    int i;
    for (i = second.length() - 1; i >= 0; i--) {
      if (i > 0 and second[i] == second[i - 1]) {
        break;
      }
    }
    if (i == -1) break;
    reverse(second.begin(), second.begin() + i);
    reverse(second.begin() + i, second.end());
  }
  int ans = 1;
  vector<int> rep(second.length(), 0);
  for (int i = 1; i < second.length(); i++) {
    if (second[i] != second[i - 1]) rep[i] = rep[i - 1] + 1;
    ans = max(ans, rep[i] + 1);
  }
  cout << ans << endl;
}
