#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, i, p;
  char s[3001], b[3001][3001];
  cin >> num;
  for (i = 1; i < num + 1; i++) {
    cin >> s;
    int p = strlen(s);
    if (s[p - 1] == 'o')
      strcpy(b[i], "FILIPION\0");
    else if (s[p - 1] == 'u')
      strcpy(b[i], "JAPANESE\0");
    else
      strcpy(b[i], "KOREAN\0");
  }
  for (i = 1; i < num + 1; i++) cout << b[i] << endl;
}
