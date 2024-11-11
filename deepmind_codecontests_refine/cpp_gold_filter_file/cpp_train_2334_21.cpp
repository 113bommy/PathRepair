#include <bits/stdc++.h>
using namespace std;
int cnt[20];
int main() {
  int n;
  cin >> n;
  string s;
  bool flag = true;
  for (int i = 0; i <= 4 - 1; i += 1) {
    cin >> s;
    for (int j = 0; j <= 4 - 1; j += 1) {
      if (s[j] == '.') continue;
      cnt[s[j] - '0']++;
      if (cnt[s[j] - '0'] > 2 * n) flag = false;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
