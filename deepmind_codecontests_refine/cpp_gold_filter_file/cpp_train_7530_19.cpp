#include <bits/stdc++.h>
using namespace std;
int num[100100];
string str;
int zimu[30];
int res[30];
int main() {
  memset(num, 0, sizeof(num));
  memset(zimu, 0, sizeof(zimu));
  cin >> str;
  int len = str.length();
  int end = -1;
  for (int i = 26; i >= 1; --i) {
    for (int j = 0; j < len; ++j)
      if (str[j] - 'a' + 1 == i && j > end) {
        zimu[str[j] - 'a' + 1]++;
        end = j;
      }
  }
  for (int i = 26; i >= 1; --i)
    for (int j = 1; j <= zimu[i]; ++j) cout << char('a' + i - 1);
  cout << endl;
  return 0;
}
