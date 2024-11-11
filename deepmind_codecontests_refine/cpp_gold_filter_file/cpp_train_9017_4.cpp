#include <bits/stdc++.h>
using namespace std;
int mp[301][301];
int main() {
  string str;
  cin >> str;
  int r = 150, c = 150;
  memset(mp, -1, sizeof(mp));
  mp[r][c] = 1;
  bool flag = true;
  int prevc, prevr, tempr, tempc;
  for (int i = 0; i < int((str).size()); i++) {
    prevr = r, prevc = c;
    switch (str[i]) {
      case 'U':
        r++;
        break;
      case 'D':
        r--;
        break;
      case 'L':
        c--;
        break;
      case 'R':
        c++;
        break;
    }
    if (mp[r][c] == -1)
      mp[r][c] = 1;
    else {
      flag = false;
      break;
    }
    if (((r + 1 != prevr || c != prevc) && mp[r + 1][c] != -1) ||
        ((r - 1 != prevr || c != prevc) && mp[r - 1][c] != -1) ||
        ((r != prevr || c - 1 != prevc) && mp[r][c - 1] != -1) ||
        ((r != prevr || c + 1 != prevc) && mp[r][c + 1] != -1))
      flag = false;
    if (!flag) break;
  }
  if (flag)
    cout << "OK" << endl;
  else
    cout << "BUG" << endl;
  return 0;
}
