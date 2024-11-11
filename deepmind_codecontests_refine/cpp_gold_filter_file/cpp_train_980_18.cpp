#include <bits/stdc++.h>
using namespace std;
char s1[25], s2[25];
int z[256][256];
int main() {
  scanf("%s%s", s1, s2);
  int S1 = 0, S2 = 0;
  z['[']['8'] = 1;
  z['(']['['] = 1;
  z['8']['('] = 1;
  for (int i = 0; s1[i] != 0; i += 2) {
    if (z[s1[i]][s2[i]]) S1++;
    if (z[s2[i]][s1[i]]) S2++;
  }
  if (S1 > S2)
    printf("TEAM 2 WINS\n");
  else if (S1 == S2)
    printf("TIE\n");
  else
    printf("TEAM 1 WINS\n");
  return 0;
}
