#include <bits/stdc++.h>
using namespace std;
char A[12][12];
int s;
void satir() {
  int i, j;
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 8; j++)
      if (A[i][j] == 'W') break;
    if (j == 9) s++;
  }
}
void sutun() {
  int i, j;
  for (j = 1; j <= 8; j++) {
    for (i = 1; i <= 8; i++)
      if (A[i][j] == 'W') break;
    if (j == 9) s++;
  }
}
void read() {
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) cin >> A[i][j];
}
int main() {
  read();
  satir();
  sutun();
  if (s == 16)
    cout << 8 << endl;
  else
    cout << s << endl;
  return 0;
}
