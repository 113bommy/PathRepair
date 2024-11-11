#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, back = 0, forr = 0, count = 0, flag = 0;
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == ')')
      back++;
    else
      forr++;
  }
  if (back != forr)
    cout << "No" << endl;
  else {
    for (i = 0; i < n; i++) {
      if (s[i] == '(')
        count++;
      else
        count--;
      if (count < -2) {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}
