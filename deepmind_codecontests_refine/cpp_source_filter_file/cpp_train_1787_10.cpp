#include <bits/stdc++.h>
using namespace std;
const int maxm = 3e5 + 120;
char que[maxm];
bool check(int l, int r) {
  for (int i = l; i <= r; i++)
    for (int j = i + 1; j <= r && (j << 1) - i <= r; j++)
      if (que[i] == que[j] && que[j] == que[(j << 1) - i]) return true;
  return false;
}
int main() {
  scanf("%s", que);
  int len = strlen(que);
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    int r = i;
    for (; r < len; r++)
      if (check(i, r)) break;
    ans += len - r;
  }
  printf("%d\n", ans);
  return 0;
}
