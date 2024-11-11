#include <bits/stdc++.h>
using namespace std;
int main() {
  int ts, stow, cntr, dir, flag = 0;
  int n, ans;
  char word[15], move[210];
  scanf("%d%d%d", &ts, &stow, &cntr);
  cin.ignore();
  scanf("%[^\n]s", word);
  scanf("%s", move);
  if (word[3] == 'h')
    dir = -1;
  else
    dir = 1;
  int a = 0;
  while (move[a]) {
    if (cntr == ts) dir *= -1;
    if (cntr == 1) dir = 1;
    if (move[a] == '0') {
      if (stow + dir <= ts && stow + dir >= 1) stow += dir;
      if (cntr + dir <= ts && cntr + dir >= 1) cntr += dir;
    } else if (move[a] == '1') {
      if (cntr + dir <= ts && cntr + dir >= 1) cntr += dir;
      if (cntr == ts)
        stow = 1;
      else if (cntr == 1)
        stow = ts;
      else if (dir == 1)
        stow = 1;
      else if (dir == -1)
        stow = ts;
    }
    if (cntr == stow) {
      flag = 1;
      ans = a + 1;
      break;
    }
    a++;
  }
  if (flag == 1)
    cout << "Controller " << ans << endl;
  else
    cout << "Stowaway" << endl;
  return 0;
}
