#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int i, j, k;
  char ch[5], s1[5], s2[5];
  char arr[10] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
  cin >> ch >> s1 >> s2;
  if (ch[0] == s1[1] && ch[0] != s2[1])
    cout << "YES";
  else if (s1[1] == s2[1]) {
    for (i = 0; i < 9; i++) {
      if (arr[i] == s1[0]) j = i;
      if (arr[i] == s2[0]) k = i;
    }
    if (j > k)
      cout << "YES";
    else
      cout << "NO";
  } else
    cout << "NO";
}
