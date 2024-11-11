#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a[3];
  char vic[3][3][3];
  vic[0][0][0] = '?';
  vic[0][0][1] = 'S';
  vic[0][0][2] = '?';
  vic[0][1][0] = 'M';
  vic[0][1][1] = '?';
  vic[0][1][2] = '?';
  vic[0][2][0] = '?';
  vic[0][2][1] = '?';
  vic[0][2][2] = '?';
  vic[1][0][0] = 'F';
  vic[1][0][1] = '?';
  vic[1][0][2] = '?';
  vic[1][1][0] = '?';
  vic[1][1][1] = '?';
  vic[1][1][2] = 'S';
  vic[1][2][0] = '?';
  vic[1][2][1] = 'M';
  vic[1][2][2] = '?';
  vic[2][0][0] = '?';
  vic[2][0][1] = '?';
  vic[2][0][2] = '?';
  vic[2][1][0] = '?';
  vic[2][1][1] = 'F';
  vic[2][1][2] = '?';
  vic[2][2][0] = 'S';
  vic[2][2][1] = '?';
  vic[2][2][2] = '?';
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (s == "rock")
      a[i] = 0;
    else if (s == "paper")
      a[i] = 1;
    else
      a[i] = 2;
  }
  cout << vic[a[0]][a[1]][a[2]] << endl;
}
