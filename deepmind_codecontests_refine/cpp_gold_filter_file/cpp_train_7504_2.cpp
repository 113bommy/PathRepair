#include <bits/stdc++.h>
using namespace std;
int n;
int query(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  char str[5];
  scanf("%s", str);
  if (str[0] == 'Y')
    return 1;
  else
    return 0;
}
stack<char> sta;
vector<char> vc;
void work() {
  int x = 1, y = 1;
  while (n - x + n - y > n - 1) {
    int z = query(x, y + 1, n, n);
    if (z) {
      vc.push_back('R');
      y++;
    } else {
      vc.push_back('D');
      x++;
    }
  }
  int nx = n, ny = n;
  while (nx != x || ny != y) {
    int z = query(1, 1, nx - 1, ny);
    if (z) {
      sta.push('D');
      nx--;
    } else {
      sta.push('R');
      ny--;
    }
  }
  printf("! ");
  for (int i = 0; i < vc.size(); i++) printf("%c", vc[i]);
  while (!sta.empty()) {
    printf("%c", sta.top());
    sta.pop();
  }
}
int main() {
  scanf("%d", &n);
  work();
  return 0;
}
