#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 10;
int n, st, x;
bool vis[MAXN];
void solve() {
  srand((unsigned)time(0));
  int val = -1, nxt = st;
  int up = min(1000, n);
  for (int i = 1; i <= up; i++) {
    int pos = abs((rand() << 15) + rand()) % n + 1;
    printf("? %d\n", pos);
    fflush(stdout);
    int tmpVal, tmpNxt;
    scanf("%d%d", &tmpVal, &tmpNxt);
    if (tmpVal == x) {
      printf("! %d\n", tmpVal);
      fflush(stdout);
      return;
    }
    if (tmpVal < x && tmpVal >= val) {
      val = tmpVal;
      nxt = tmpNxt;
    }
  }
  while (val < x && nxt != -1) {
    printf("? %d\n", nxt);
    fflush(stdout);
    scanf("%d%d", &val, &nxt);
  }
  if (val >= x)
    printf("! %d\n", val);
  else
    printf("! -1\n");
  fflush(stdout);
}
int main() {
  scanf("%d%d%d", &n, &st, &x);
  solve();
  return 0;
}
