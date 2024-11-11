#include <bits/stdc++.h>
using namespace std;
string s, ans;
long long n, q[10000];
map<char, int> cnt;
int main() {
  cin >> n;
  cin >> s;
  if (n == 1) {
    cout << s;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    q[int(s[i]) - 97]++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (q[i] % n != 0) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < q[i] / n; j++) {
      ans += char(i + 97);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans;
  }
  return 0;
}
