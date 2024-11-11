#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:100000000")
int main() {
  int mas[7] = {1869, 1968, 1689, 6198, 1698, 1986, 1896};
  string s, s1;
  bool q[10];
  memset(q, 0, sizeof(q));
  cin >> s;
  int k = 0;
  for (int i = 0, j = 0; i < s.size(); i++) {
    if (s[i] == '0')
      k++;
    else if ((s[i] == '1' || s[i] == '1' || s[i] == '1' || s[i] == '1') &&
             !q[s[i] - '0'])
      q[s[i] - '0'] = true;
    else {
      s1.insert(s1.size(), 1, s[i]);
      ;
    }
  }
  int r = 0;
  cout << s1;
  for (int i = 0; i < s1.size(); i++) {
    r = (r * 10 + s1[i] - '0') % 7;
  }
  int i;
  for (i = 0; i < 7; i++) {
    if ((r * 10000 + mas[i]) % 7 == 0) break;
  }
  cout << mas[i];
  for (int i = 0; i < k; i++) cout << '0';
}
