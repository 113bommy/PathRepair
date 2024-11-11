#include <bits/stdc++.h>
using namespace std;
char s[2][15];
int check(int chang, int way) {
  int ans = -10;
  int k = 1;
  for (int i = 0; i < (chang + 1) / 2; i++) {
    if (s[way][i] != s[way][chang - k - i]) {
      if (k)
        k = 0, ans = i;
      else
        return -1;
    }
  }
  return ans;
}
void out(int x, int chang, int way) {
  for (int i = 0; i < chang - x; i++) cout << s[way][i];
  cout << s[way][x];
  for (int i = chang - x; i < chang; i++) cout << s[way][i];
  cout << endl;
  return;
}
int main() {
  cin >> s[0];
  int chang = strlen(s[0]);
  for (int i = 0; i < chang; i++) s[1][i] = s[0][chang - 1 - i];
  int dir = (chang + 1) / 2 - 1;
  int flag1, flag2;
  flag1 = check(chang, 0);
  flag2 = check(chang, 1);
  if (flag1 == -1 && flag2 == -1) {
    cout << "NA" << endl;
    return 0;
  }
  if (flag1 == -10 && flag2 == -10) {
    out(dir, chang, 0);
    return 0;
  }
  if (flag2 >= 0) {
    out(flag2, chang, 1);
    return 0;
  }
  if (flag1 >= 0) {
    out(flag1, chang, 0);
    return 0;
  }
}
