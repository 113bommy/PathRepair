#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  char pass[3][3];
  bool fs = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> pass[i][j];
  int a = 2;
  for (int i = 0; i < 3; i++) {
    if (pass[0][i] == pass[2][a])
      fs = 1;
    else {
      fs = 0;
      break;
    }
    a--;
  }
  if (pass[0][1] == pass[2][1])
    if (fs)
      cout << "YES";
    else
      cout << "NO";
  else
    cout << "NO";
  return (EXIT_SUCCESS);
}
