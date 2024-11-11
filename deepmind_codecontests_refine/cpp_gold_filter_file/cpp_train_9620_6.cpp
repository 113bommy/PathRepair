#include <bits/stdc++.h>
using namespace std;
char c;
int cnt, ans;
int main() {
  while (~scanf(" %c", &c)) {
    if (c == 'M')
      cnt++;
    else if (cnt)
      ans = max(ans + 1, cnt);
  }
  printf("%d\n", ans);
}
