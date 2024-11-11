#include <bits/stdc++.h>
using namespace std;
const int MAX = 1111;
const int inf = 1e7 + 3;
const long long mod = 1e9 + 7;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size() / 2; ++i)
    if (str[i] == 'p')
      str[i] = 'q';
    else if (str[i] == 'q')
      str[i] = 'p';
    else if (str[i] == 'b')
      str[i] = 'd';
    else if (str[i] == 'd')
      str[i] = 'b';
    else if (str[i] != 'H' && str[i] != 'I' && str[i] != 'A' && str[i] != 'M' &&
             str[i] != 'O' && str[i] != 'o' && str[i] != 'T' && str[i] != 'W' &&
             str[i] != 'w' && str[i] != 'U' && str[i] != 'V' && str[i] != 'v' &&
             str[i] != 'X' && str[i] != 'x' && str[i] != 'Y')
      str[i] = '@';
  for (int i = 0; i < str.size() / 2; ++i)
    if (str[i] != str[str.size() - 1 - i]) return puts("NIE");
  int i = str.size() / 2;
  if (str.size() % 2 == 0)
    puts("TAC");
  else if (str[i] != 'H' && str[i] != 'I' && str[i] != 'A' && str[i] != 'M' &&
           str[i] != 'O' && str[i] != 'o' && str[i] != 'T' && str[i] != 'W' &&
           str[i] != 'w' && str[i] != 'U' && str[i] != 'V' && str[i] != 'v' &&
           str[i] != 'X' && str[i] != 'x' && str[i] != 'Y')
    puts("NIE");
  else
    puts("TAC");
  return 0;
}
