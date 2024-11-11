#include <bits/stdc++.h>
using namespace std;
int main() {
  int lines;
  cin >> lines;
  int p[lines], j = 0, flag;
  for (int i = 0; i < lines; i++) cin >> p[i];
  cin.ignore(256, '\n');
  while (lines--) {
    string str;
    getline(cin, str);
    int count = 0;
    flag = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u' || str[i] == 'y')
        count++;
    }
    if (count >= p[j++]) flag = 1;
    if (flag == 0) break;
  }
  if (flag == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
