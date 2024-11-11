#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int flag = 0;
int main() {
  cin >> s1 >> s2;
  int i = s1.size() - 1;
  int j = 0;
  while (i > 0 && j < s2.size() - 1) {
    if (s1[i] != s2[j]) {
      flag = 1;
      break;
    }
    i--;
    j++;
  }
  if (flag)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
