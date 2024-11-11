#include <bits/stdc++.h>
using namespace std;
int main(void) {
  map<int, int> m;
  m[1] = 31;
  m[2] = 28;
  m[3] = 31;
  m[4] = 30;
  m[5] = 31;
  m[6] = 30;
  m[7] = 31;
  m[8] = 31;
  m[9] = 30;
  m[10] = 31;
  m[11] = 30;
  m[12] = 31;
  int dd[3];
  int bd[3];
  scanf("%d.%d.%d", dd, dd + 1, dd + 2);
  scanf("%d.%d.%d", bd, bd + 1, bd + 2);
  sort(bd, bd + 3);
  do {
    if (bd[1] > 12) continue;
    if (!(bd[1] == 2 && bd[2] % 4 == 0 && bd[0] == 29)) {
      if (bd[0] > m[bd[1]]) continue;
    }
    int age = 0;
    age = dd[2] - bd[2];
    if (bd[1] > dd[1] || (bd[1] == dd[1] && bd[0] > dd[0])) age--;
    if (age >= 18) {
      cout << "YES" << endl;
      return 0;
    }
  } while (next_permutation(bd, bd + 3));
  cout << "NO" << endl;
  return 0;
}
