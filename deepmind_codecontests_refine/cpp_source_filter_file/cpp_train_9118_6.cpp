#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
char a[251];
int main() {
  cin >> n >> a;
  int m = strlen(a);
  if (a[m - 1] != '0') a[m] = '0';
  for (int i = 0; i <= m; i++) {
    if (a[i] == '1' && a[i + 1] == '0') {
      ans++;
      printf("%d", ans);
      ans = 0;
      i = i + 2;
      continue;
    } else if (a[i] == '0') {
      printf("0");
    } else if (a[i] == '1')
      ans++;
  }
  return 0;
}
