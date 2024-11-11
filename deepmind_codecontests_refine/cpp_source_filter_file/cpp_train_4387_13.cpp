#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2[5];
  int i, flag = 0;
  cin >> s1;
  for (i = 0; i < 5; ++i) {
    cin >> s2[i];
  }
  for (i = 0; i < 5; ++i) {
    if (s1[0] == s2[i][0] or s1[0] == s2[i][1]) {
      ++flag;
      break;
    }
  }
  if (flag == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
