#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  bool all = true;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != str[i + 1]) all = false;
  }
  if (all) {
    cout << 0 << endl;
    return 0;
  }
  int i = 0;
  int j = str.size() - 1;
  bool pal = true;
  while (i < j) {
    if (str[i] != str[j]) pal = false;
    i++;
    j--;
  }
  if (!pal)
    cout << str.size() << endl;
  else
    cout << str.size() - 1 << endl;
  return 0;
}
