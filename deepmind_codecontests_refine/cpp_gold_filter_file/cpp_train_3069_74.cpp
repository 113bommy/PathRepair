#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch;
  int suma = 0, sum = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> ch;
      if (isalpha(ch)) {
        if (ch == 'Q') sum += 9;
        if (ch == 'R') sum += 5;
        if (ch == 'B') sum += 3;
        if (ch == 'N') sum += 3;
        if (ch == 'P') sum += 1;
        if (ch == 'q') suma += 9;
        if (ch == 'r') suma += 5;
        if (ch == 'b') suma += 3;
        if (ch == 'n') suma += 3;
        if (ch == 'p') suma += 1;
      }
    }
    getchar();
  }
  if (suma < sum)
    cout << "White" << endl;
  else if (suma > sum)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
