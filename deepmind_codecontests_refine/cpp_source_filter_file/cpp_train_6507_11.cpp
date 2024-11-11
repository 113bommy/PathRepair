#include <bits/stdc++.h>
using namespace std;
string s[1005];
int a[1005];
string s1;
int main() {
  int max_len = 0, n = 0, i, j;
  while (getline(cin, s[++n])) {
    int len = s[n].size();
    max_len = max(max_len, len);
    a[n] = s[n].size();
  }
  for (i = 0; i <= max_len + 1; i++) cout << '*';
  puts("");
  int x = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] % 2 == max_len % 2) {
      cout << '*';
      for (j = 1; j <= (max_len - a[i]) / 2; j++) cout << ' ';
      cout << s[i];
      for (j = 1; j <= (max_len - a[i]) / 2; j++) cout << ' ';
      puts("*");
    } else {
      cout << '*';
      for (j = 1; j <= (max_len - a[i]) / 2 + x; j++) cout << ' ';
      cout << s[i];
      for (j = 1; j <= (max_len - a[i] + 1) / 2 - x; j++) cout << ' ';
      puts("*");
      x = (x == 0);
    }
  }
  for (i = 0; i <= max_len + 1; i++) cout << '*';
  puts("");
  return 0;
}
