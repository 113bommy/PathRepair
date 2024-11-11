#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2, s;
int cal(string s1, string s2) {
  int h = (s1[1] - '0') * 10 + (s1[2] - '0');
  int m = (s1[4] - '0') * 10 + (s1[5] - '0');
  if (h == 12) h = 0;
  if (s2[0] == 'p') h += 1000;
  return h * 100000 + m;
}
int main() {
  cin >> n;
  cin.get();
  int ans = 1;
  getline(cin, s);
  stringstream ss(s);
  ss >> s1 >> s2;
  int last = cal(s1, s2), now, cou = 1;
  for (int i = 1; i < n; i++) {
    getline(cin, s);
    stringstream ss(s);
    ss >> s1 >> s2;
    now = cal(s1, s2);
    if (now < last)
      ans++, cou = 1;
    else if (now == last)
      cou++;
    else
      cou = 1;
    if (cou > 10) ans++, cou = 1;
    last = now;
  }
  cout << ans << endl;
  return 0;
}
