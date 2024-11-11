#include <bits/stdc++.h>
using namespace std;
map<string, int> us;
string s[200010], s1[200010];
int main() {
  long long n, i, j = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (i = n; i >= 1; i--) {
    if (us[s[i]] == 0) {
      us[s[i]] = 1;
      j++;
      s1[j] = s[i];
    } else
      us[s[i]] = 0;
  }
  for (i = 1; i <= j; i++) {
    cout << s1[i] << '\n';
  }
  return 0;
}
