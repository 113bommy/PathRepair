#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = 0; i < s.length(); i++) {
    int cn = s.at(i);
    if (cn >= 97) {
      if (cn - 'a' + 1 <= n)
        printf("%c", cn - 'a' + 'A');
      else
        printf("%c", cn);
    } else {
      if (cn - 'A' + 1 > 14)
        printf("%c", cn + 'a' - 'A');
      else
        printf("%c", cn);
    }
  }
  printf("\n");
  return 0;
}
