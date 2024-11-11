#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int Size = 1000 * 1000 + 1;
char buffer[Size];
int res[] = {3, 1, 3, 2, 3};
int solution(int nTest) {
  int a;
  scanf("%d", &a);
  a--;
  printf("%d\n", res[a]);
  return 0;
}
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int i = 0, n = 99999;
  while (i < n && solution(i)) {
    i++;
  }
  return 0;
}
