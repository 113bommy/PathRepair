#include <bits/stdc++.h>
using namespace std;
int n, p;
char st[2005];
int main() {
  cin >> n >> p;
  scanf("%s", st + 1);
  bool tmp = false;
  for (int i = 1; i <= n - p; i++) {
    if (st[i] == '.' || st[i + p] == '.' || st[i] != st[i + p]) tmp = true;
  }
  if (n == p || tmp == false) {
    puts("No");
    return 0;
  } else {
    for (int i = 1; i <= n - p; i++) {
      if (st[i] == '.') {
        if (st[i + p] == '1')
          st[i] = '0';
        else if (st[i + p] == '0')
          st[i] = '1';
        else
          st[i] = '0', st[i + p] = '1';
      } else if (st[i + p] == '.') {
        if (st[i] == '0')
          st[i + p] = '1';
        else
          st[i + p] = '0';
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (st[i] == '.') st[i] = '0';
    printf("%c", st[i]);
  }
  puts("");
  return 0;
}
