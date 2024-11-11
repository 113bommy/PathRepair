#include <bits/stdc++.h>
using namespace std;
const char C[] = {'A', 'E', 'F', 'H', 'I', 'K', 'L', 'M',
                  'N', 'T', 'V', 'W', 'X', 'Y', 'Z', ' '};
bool Yes[200];
char S[200];
int main() {
  int Now = 0, tot = 0;
  while (C[Now] != ' ') Yes[C[Now]] = 1, (++(Now));
  cin >> S;
  for (int i = (0), iLimit = (strlen(S) - 1); i <= iLimit; (++(i)))
    tot += Yes[S[i]];
  if (tot != strlen(S) && tot)
    puts("NO");
  else
    puts("YES");
  return 0;
}
