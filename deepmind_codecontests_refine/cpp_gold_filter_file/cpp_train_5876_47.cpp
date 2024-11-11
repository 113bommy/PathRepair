#include <bits/stdc++.h>
using namespace std;
int main() {
  char word[101], s[101];
  cin >> word >> s;
  int len = strlen(word), flag = 1;
  for (int i = 0; i < len; i++)
    if (s[i] != word[len - 1 - i]) {
      flag = 0;
      break;
    }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
