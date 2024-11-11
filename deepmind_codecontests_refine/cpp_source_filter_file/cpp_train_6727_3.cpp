#include <bits/stdc++.h>
using namespace std;
int main() {
  char temp;
  int concount = 0;
  bool same = true;
  char first = 0;
  while (isalpha(temp = getchar())) {
    if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' ||
        temp == 'u') {
      concount = 0;
      same = true;
      first = 0;
    } else {
      if (concount == 0) {
        same = true;
        first = temp;
        concount = 1;
      } else {
        concount++;
        same = (temp == first);
      }
    }
    if (concount >= 3 && same != true) {
      putchar(' ');
      first = temp;
      same = true;
      concount = 1;
    }
    putchar(temp);
  }
  return 0;
}
