#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 1 << 27;
char mp[10][10];
int up(int i, int j) {
  int cnt = 1;
  while (i >= 0 && mp[i][j] == '.') i--, cnt++;
  if (i >= 0) return inf;
  return cnt;
}
int down(int i, int j) {
  int cnt = 1;
  while (i < 8 && mp[i][j] == '.') i++, cnt++;
  if (i < 8) return inf;
  return cnt;
}
int main() {
  int A = inf, B = inf;
  for (int i = 0; i < 8; i++) {
    scanf("%s", mp[i]);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (mp[i][j] == 'W') {
        A = min(A, up(i - 1, j));
      }
      if (mp[i][j] == 'B') {
        B = min(B, down(i + 1, j));
      }
    }
  }
  if (A <= B) {
    puts("A");
  } else {
    puts("B");
  }
  return 0;
}
