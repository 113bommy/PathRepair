#include <bits/stdc++.h>
using namespace std;
const int N = 700 + 50;
const int mo = 1e9 + 7;
string ss;
int f[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int n, m;
int main() {
  char s[10];
  scanf("%s", s);
  int x = s[0] - '0';
  int y = s[1] - '0';
  int ans = (f[x] * f[y]);
  printf("%d", ans);
  return 0;
}
