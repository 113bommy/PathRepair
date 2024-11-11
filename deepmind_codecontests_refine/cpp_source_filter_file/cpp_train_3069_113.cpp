#include <bits/stdc++.h>
using namespace std;
int main() {
  long long counta = 0, countA = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      char s;
      cin >> s;
      if (s != '.') {
        if (s >= 'a' && s <= 'z') {
          if (s == 'q') {
            counta += 9;
          } else if (s == 'r') {
            counta += 5;
          } else if (s == 'b' || s == 'n') {
            counta += 3;
          } else if (s == 'p') {
            counta++;
          }
        } else {
          if (s == 'Q') {
            counta += 9;
          } else if (s == 'R') {
            counta += 5;
          } else if (s == 'B' || s == 'N') {
            counta += 3;
          } else if (s == 'P') {
            counta++;
          }
        }
      }
    }
  if (counta > countA)
    cout << "Black";
  else if (counta < countA)
    cout << "White";
  else
    cout << "Draw";
  return 0;
}
