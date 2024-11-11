#include <bits/stdc++.h>
using namespace std;
char s[200];
char d[] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
int main() {
  scanf("%[^\n]s", s);
  int a = strlen(s) - 1, b;
  for (int i = a - 2; i >= 0; i--)
    if (s[i] != ' ') {
      b = i;
      break;
    }
  for (int i = 0; i < 12; i++) {
    if (s[b] == d[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
