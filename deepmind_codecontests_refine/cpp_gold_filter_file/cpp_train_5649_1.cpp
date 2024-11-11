#include <bits/stdc++.h>
using namespace std;
int nTest;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> nTest;
  for (int iTest = 1; iTest <= nTest; ++iTest) {
    cin >> s;
    int n = s.size();
    int cur = 0;
    int mn = 0;
    long long res = n;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '+') {
        cur++;
      } else {
        cur--;
      }
      if (cur < mn) {
        mn = cur;
        res += i + 1;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
