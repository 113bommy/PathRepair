#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count = 0, count1 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4') {
      count++;
    }
    if (s[i] == '7') {
      count1++;
    }
  }
  if ((count >= count1) && (count > 0)) {
    cout << "4" << endl;
  } else if ((count1 > count) && (count > 0)) {
    cout << "7" << endl;
  } else
    cout << "-1";
  return 0;
}
