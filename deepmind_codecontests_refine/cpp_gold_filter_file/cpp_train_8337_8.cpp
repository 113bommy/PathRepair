#include <bits/stdc++.h>
using namespace std;
int main() {
  string t, temp;
  int l, n;
  cin >> l >> n;
  cin >> t;
  for (int i = 1; i <= t.size(); i++) {
    int x = 1;
    for (int j = i; j < t.size(); j++) {
      if (t[j] != t[j - i]) {
        x = 0;
        break;
      }
    }
    if (x) {
      for (int k = t.size() - i; k < t.size(); k++) temp.push_back(t[k]);
      break;
    }
  }
  string ans = t;
  n--;
  while (n--) ans.append(temp);
  cout << ans;
  return 0;
}
