#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1, str2;
  cin >> str1 >> str2;
  int siz = str1.size();
  siz--;
  while (siz > -1) {
    if (str1[siz] == 'z') {
      str1[siz] = 'a';
      siz--;
    } else {
      str1[siz]++;
      break;
    }
  }
  if (siz == -1 || str1 == str2)
    cout << "No such string" << endl;
  else
    cout << str1 << endl;
  return 0;
}
