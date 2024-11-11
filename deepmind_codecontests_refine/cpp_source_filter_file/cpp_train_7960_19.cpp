#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s2;
  int a;
  cin >> a;
  cin >> s;
  string s1[] = {"", "", "2", "3", "223", "5", "35", "7", "227", "2337"};
  for (int i = 0; i < s.size(); i++) {
    s2 += s1[s[i] - '0'];
  }
  sort(s2.begin(), s2.end());
  reverse(s2.begin(), s2.end());
  cout << s2 << endl;
  return 0;
}
