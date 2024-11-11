#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int i = 0;
  char res[10000], k = 0;
  while (i < str.length()) {
    if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B')
      i = i + 3;
    else {
      res[k++] = str[i];
      if (str[i + 1] == 'W' && str[i + 2] == 'U' && str[i + 3] == 'B')
        res[k++] = ' ';
      i++;
    }
  }
  for (int i = 0; i < strlen(res); i++) cout << res[i];
  return 0;
}
