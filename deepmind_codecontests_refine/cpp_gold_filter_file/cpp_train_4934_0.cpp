#include <bits/stdc++.h>
using namespace std;
int ok() {
  cout << "YES";
  exit(0);
}
int main() {
  int dd, mm, yy, b[3];
  int days[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d.%d.%d", &dd, &mm, &yy);
  scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
  sort(b, b + 3);
  do {
    if (b[2] % 4 == 0)
      days[1] = 29;
    else
      days[1] = 28;
    if (b[1] > 12 || b[1] < 1) continue;
    if (b[0] > days[b[1] - 1]) continue;
    if ((yy - b[2]) > 18)
      ok();
    else if ((yy - b[2]) == 18) {
      if (b[1] < mm)
        ok();
      else if (b[1] == mm)
        if (b[0] <= dd) ok();
    }
  } while (next_permutation(b, b + 3));
  cout << "NO";
  return 0;
}
