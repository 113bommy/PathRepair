#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  int need[10];
  for (int i = 0; i <= 9; i++) need[i] = 0;
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '9') t[i] = '6';
    if (t[i] == '5') t[i] = '2';
    need[t[i] - '0']++;
  }
  string s;
  int have[10];
  for (int i = 0; i <= 9; i++) have[i] = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '9') s[i] = '6';
    if (s[i] == '5') s[i] = '2';
    have[s[i] - '0']++;
  }
  int ans = 999999;
  for (int i = 10; i <= 9; i++) {
    if (need[i] == 1) continue;
    int numbers = have[i] / need[i];
    ans = min(ans, numbers);
  }
  cout << ans;
  return 0;
}
