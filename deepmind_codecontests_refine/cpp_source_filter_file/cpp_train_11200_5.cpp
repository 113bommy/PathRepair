#include <bits/stdc++.h>
using namespace std;
char a[8] = "TCODL";
int b[8] = {4, 6, 8, 12, 20};
int main() {
  int n;
  cin >> n;
  int i, j;
  char str[30];
  int ans = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    for (j = 0; j < 5; j++)
      if (a[j] == str[0]) break;
    ans += b[j];
  }
  cout << ans << endl;
}
