#include <bits/stdc++.h>
using namespace std;
int grundyTable[6][6], grundyNumber[6];
int main() {
  int n, ans = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j <= i; j++) {
      set<int> s;
      for (int x = 0; x < 6; x++) s.insert(x);
      for (int k = 0; k < j; k++) s.erase(grundyTable[i - j][k]);
      grundyTable[i][j] = *s.begin();
    }
    set<int> s;
    for (int x = 0; x < 6; x++) s.insert(x);
    for (int j = 1; j <= i; j++) s.erase(grundyTable[i - j][j - 1]);
    grundyNumber[i] = *s.begin();
  }
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    ans ^= grundyNumber[x];
  }
  if (ans)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
