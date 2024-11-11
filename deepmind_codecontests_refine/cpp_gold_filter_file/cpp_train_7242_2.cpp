#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool x = false;
  int counter = 0;
  int counterofB = 0;
  int counterofb = 0;
  int counterofa = 0;
  int counterofu = 0;
  int counterofs = 0;
  int counterofr = 0;
  int counterofl = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      counterofB++;
    } else if (s[i] == 'b') {
      counterofb++;
    } else if (s[i] == 'a') {
      counterofa++;
    } else if (s[i] == 'u') {
      counterofu++;
    } else if (s[i] == 's') {
      counterofs++;
    } else if (s[i] == 'r') {
      counterofr++;
    } else if (s[i] == 'l') {
      counterofl++;
    }
  }
  while (x == false) {
    if (counterofa >= 2 && counterofB >= 1 && counterofr >= 1 &&
        counterofs >= 1 && counterofu >= 2 && counterofb >= 1 &&
        counterofl >= 1) {
      counter++;
      counterofa -= 2;
      counterofB -= 1;
      counterofr -= 1;
      counterofu -= 2;
      counterofb -= 1;
      counterofs -= 1;
      counterofl -= 1;
    } else {
      x = true;
      break;
    }
  }
  cout << counter << endl;
  return 0;
}
