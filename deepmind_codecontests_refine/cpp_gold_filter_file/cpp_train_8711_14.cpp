#include <bits/stdc++.h>
using namespace std;
char str[10];
string ans[7];
bool vis[10];
int main() {
  int n;
  scanf("%d", &n);
  ans[1] = "Power";
  ans[2] = "Time";
  ans[3] = "Space";
  ans[4] = "Soul";
  ans[5] = "Reality";
  ans[6] = "Mind";
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    if (str[0] == 'p') vis[1] = 1;
    if (str[0] == 'g') vis[2] = 1;
    if (str[0] == 'b') vis[3] = 1;
    if (str[0] == 'o') vis[4] = 1;
    if (str[0] == 'r') vis[5] = 1;
    if (str[0] == 'y') vis[6] = 1;
  }
  printf("%d\n", 6 - n);
  for (int i = 1; i <= 6; i++) {
    if (!vis[i]) {
      cout << ans[i] << endl;
    }
  }
}
