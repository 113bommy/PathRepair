#include <bits/stdc++.h>
using namespace std;
vector<int> divisor[100005];
int last[50005];
int main() {
  int j;
  for (int i = 1; i <= 100000; i++) {
    last[i] = -1;
    j = i;
    while (j <= 100000) {
      divisor[j].push_back(i);
      j += i;
    }
  }
  int n;
  scanf("%d", &n);
  int x, y, bg;
  int cnt;
  for (int i = 0; i < n; i++) {
    cnt = 0;
    scanf("%d %d", &x, &y);
    if (y == 0) {
      printf("%d\n", divisor[x].size());
    } else {
      bg = i - y;
      if (bg < 0) bg = 0;
      for (j = 0; j < divisor[x].size(); j++) {
        if (last[divisor[x][j]] < bg) cnt++;
      }
      printf("%d\n", cnt);
    }
    for (j = 0; j < divisor[x].size(); j++) last[divisor[x][j]] = i;
  }
  return 0;
}
