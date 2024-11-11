#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int arr[s.size()];
    int cur = 0;
    long long ans = 0;
    int prev = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '+') {
        cur++;
      } else {
        cur--;
      }
      if (cur < 0 && prev > cur) {
        ans += (i + 1);
        prev = cur;
      }
    }
    ans += s.size();
    cout << ans << "\n";
  }
}
