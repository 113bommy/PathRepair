#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
string s;
int main() {
  while (cin >> s) {
    int next;
    if (s[0] == 'f') {
      printf("%c%c%c://", s[0], s[1], s[2]);
      next = 3;
    } else {
      printf("%c%c%c%c://", s[0], s[1], s[2], s[3]);
      next = 4;
    }
    int i;
    for (i = next + 1; i < s.length(); i++)
      if (s[i] == 'r' && s[i + 1] == 'u') break;
    int j;
    while (next < i) {
      printf("%c", s[next]);
      next++;
    }
    putchar('.');
    printf("ru");
    i += 2;
    if (i >= s.length()) {
      puts("");
      continue;
    }
    putchar('/');
    while (i < s.length()) putchar(s[i++]);
    puts("");
  }
  return 0;
}
