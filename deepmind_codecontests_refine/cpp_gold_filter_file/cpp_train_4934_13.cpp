#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
char str[10];
int dd[2][3];
int dm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int k = 0;
  for (int i = 0; i < 6; i++) {
    scanf("%3s", str);
    dd[i > 2][k++] = atoi(str);
    if (i == 2) k = 0;
  }
  sort(dd[1], dd[1] + 3);
  do {
    if (dd[1][1] <= 12 &&
        dd[1][0] <= dm[dd[1][1] - 1] + 1 * (dd[1][1] == 2 && dd[1][2] % 4 == 0))
      if (dd[0][2] - dd[1][2] > 18 ||
          dd[0][2] - dd[1][2] == 18 && dd[0][1] - dd[1][1] > 0 ||
          dd[0][2] - dd[1][2] == 18 && dd[0][1] - dd[1][1] == 0 &&
              dd[0][0] - dd[1][0] >= 0) {
        puts("YES");
        return 0;
      }
  } while (next_permutation(dd[1], dd[1] + 3));
  puts("NO");
  return 0;
}
