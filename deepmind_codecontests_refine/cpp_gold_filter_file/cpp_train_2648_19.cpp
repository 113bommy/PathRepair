#include <bits/stdc++.h>
using namespace std;
int a[5], b[5], t[5];
int att(int x, int y) {
  if (b[x] > a[y])
    return 1;
  else if (b[x] < a[y])
    return -1;
  else
    return 0;
}
int main() {
  for (int i = 1; i <= 4; i++) cin >> a[i] >> b[i];
  t[1] = att(1, 3) - att(4, 2);
  t[2] = att(1, 4) - att(3, 2);
  t[3] = att(2, 3) - att(4, 1);
  t[4] = att(2, 4) - att(3, 1);
  int goal = 0;
  if (t[1] > 1 && t[2] > 1) {
    goal = 1;
    goto end;
  }
  if (t[3] > 1 && t[4] > 1) {
    goal = 1;
    goto end;
  }
  if ((t[1] < -1 || t[2] < -1) && (t[3] < -1 || t[4] < -1)) {
    goal = 2;
    goto end;
  }
end:;
  if (goal == 1)
    cout << "Team 1" << endl;
  else if (goal == 2)
    cout << "Team 2" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
