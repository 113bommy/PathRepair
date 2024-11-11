#include <bits/stdc++.h>
using namespace std;
char team1[21], team2[21];
int sum_1, sum_2;
int comb(char arr[21], int i) {
  if ((arr[i] == '(') && (arr[i + 1] == ')'))
    return 1;
  else if (arr[i] == '[' && arr[i + 1] == ']')
    return 2;
  else if (arr[i] == '8' && arr[i + 1] == '<')
    return 3;
  return 1;
}
void points(void) {
  for (int i = 0; i < (int)strlen(team1); i += 2) {
    int comb_1 = comb(team1, i);
    int comb_2 = comb(team2, i);
    if (comb_1 != comb_2) {
      if ((comb_1 == 2 && comb_2 == 1) || (comb_1 == 1 && comb_2 == 3) ||
          (comb_1 == 3 && comb_2 == 2))
        ++sum_1;
      else
        ++sum_2;
    }
  }
}
int main() {
  scanf("%s\n%s", team1, team2);
  points();
  if (sum_1 > sum_2)
    printf("%s\n", "TEAM 1 WINS");
  else if (sum_1 < sum_2)
    printf("%s\n", "TEAM 2 WINS");
  else
    printf("%s\n", "TIE");
  return 0;
}
