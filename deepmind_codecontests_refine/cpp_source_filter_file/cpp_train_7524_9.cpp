#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long cnt[26], now[26], all = 0, rez = 0;
int main(void) {
  string s, c;
  cin >> s >> c;
  if (s.size() < c.size()) cout << 0 << endl, exit(0);
  for (int i = 0; i < c.size(); i++) {
    cnt[c[i] - 'a']++;
  }
  for (int i = 0; i < c.size() - 1; i++) {
    if (s[i] == '?')
      all++;
    else
      now[s[i] - 'a']++;
  }
  long long L = 0;
  for (int i = c.size(); i < s.size(); i++) {
    if (s[i] == '?')
      all++;
    else
      now[s[i] - 'a']++;
    long long N = all;
    bool ok = true;
    for (int j = 0; j < 26; j++) {
      if (now[j] > cnt[j]) {
        ok = false;
        break;
      }
      if (now[j] == cnt[j]) continue;
      if (now[j] < cnt[j]) N -= (cnt[j] - now[j]);
      if (N < 0) {
        ok = false;
        break;
      }
    }
    if (ok) rez++;
    if (s[L] == '?')
      all--;
    else
      now[s[L] - 'a']--;
    L++;
  }
  cout << rez << endl;
  return 0;
}
