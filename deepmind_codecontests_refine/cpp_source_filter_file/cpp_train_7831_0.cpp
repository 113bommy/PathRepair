#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    int a = 0, b = 0;
    string ans = "";
    cin >> str;
    int n = int((str).size());
    for (long long i = 0; i < n; i++) {
      if (str[i] == '1') a++;
      if (str[i] == '0') b++;
    }
    if (a == n) {
      for (long long i = 0; i < n; i++) ans.push_back('1');
      cout << ans << '\n';
      continue;
    }
    if (b == n) {
      for (long long i = 0; i < n; i++) ans.push_back('0');
      cout << ans << '\n';
      continue;
    }
    int ok = 0;
    for (long long i = 0; i < n; i++) {
      ans.push_back(ok + '0');
      ok ^= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
