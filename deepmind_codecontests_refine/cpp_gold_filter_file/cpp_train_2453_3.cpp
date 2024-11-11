#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 3e5;
string s1, s2;
int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int get(string s) {
  if (s[0] == 'm')
    return 0;
  else if (s[0] == 't' && s[1] == 'u')
    return 1;
  else if (s[0] == 'w')
    return 2;
  else if (s[0] == 't')
    return 3;
  else if (s[0] == 'f')
    return 4;
  else if (s[1] == 'a')
    return 5;
  else
    return 6;
}
int main() {
  cin >> s1 >> s2;
  int t0 = get(s1);
  int t1 = get(s2);
  for (int i = 0; i < 7; ++i) {
    int now = i;
    for (int j = 0; j < 11; ++j) {
      int cur = now + mon[j];
      cur %= 7;
      if (now == t0 && cur == t1) {
        cout << "YES" << endl;
        return 0;
      }
      now = cur;
    }
  }
  cout << "NO" << endl;
  return 0;
}
