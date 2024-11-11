#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    vector<int> s;
    int diff, ans, i = 1, sum = 0;
    diff = abs(a - b);
    while (sum <= 2000000000) {
      sum += i;
      s.push_back(sum);
      i++;
    }
    if (diff == 0) {
      cout << 0 << "\n";
    } else {
      for (int i = 0; i < s.size(); i++) {
        if ((s[i] + diff) % 2 == 0 && (s[i] - diff) % 2 == 0 && s[i] >= diff) {
          ans = i + 1;
          break;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
