#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "";
  char c;
  long long a1 = 0, a2 = 0;
  while (scanf("%c", &c) != EOF && c != '^') {
    s += c;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '=') a1 += (s[i] - '0') * (s.size() - i);
  }
  s = "";
  while (scanf("%c", &c) != EOF && c != '\n') {
    s += c;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '=') a2 += (s[i] - '0') * (i + 1);
  }
  if (a1 > a2)
    printf("left");
  else if (a2 > a1)
    printf("right");
  else
    printf("balance");
  return 0;
}
