#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100000], news[100000];
  cin >> s;
  int l = strlen(s), x = 0, i;
  for (i = 0; i < l;) {
    if (s[i] == '.') {
      news[x] = '0';
      x++;
      i = i + 1;
    } else if (s[i] == '-' && s[i + 1] == '.') {
      i = i + 2;
      news[x] = '1';
      x++;
    } else if (s[i] == '-' && s[i + 1] == '-') {
      i = i + 2;
      news[x] = '2';
      x++;
    }
  }
  cout << news;
  return 0;
}
