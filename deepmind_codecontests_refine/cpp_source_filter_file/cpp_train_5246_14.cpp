#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char s[1005];
  int n, startofright = 0, endofright = 0, startofleft = 0, endofleft = 0,
         i = 0;
  cin >> s >> n;
  for (i = 0; i < n; i++)
    if (s[i] == 'R') {
      startofright = i + 1;
      break;
    }
  for (i = 0; i < n; i++)
    if (s[i] == 'L') {
      startofleft = i + 1;
      break;
    }
  for (i = n - 1; i > 0; i--)
    if (s[i] == 'R') {
      endofright = i + 1;
      break;
    }
  for (i = n - 1; i > 0; i--)
    if (s[i] == 'L') {
      endofleft = i + 1;
      break;
    }
  if (startofright == 0 && startofleft == 0) cout << "1 1" << endl;
  if (startofright != 0 && startofleft == 0)
    cout << startofright << " " << endofright + 1 << endl;
  if (startofright == 0 && startofleft != 0)
    cout << endofleft << " " << startofleft - 1 << endl;
  if (startofright != 0 && startofleft != 0)
    cout << startofright << " " << startofleft - 1 << endl;
  return 0;
}
