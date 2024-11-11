#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main(void) {
  int mas[16];
  mas[0] = 1;
  mas[1] = 0;
  mas[2] = 0;
  mas[3] = 1;
  mas[4] = 0;
  mas[5] = 1;
  mas[6] = 0;
  mas[7] = 1;
  mas[8] = 1;
  mas[9] = 1;
  mas[10] = 0;
  mas[11] = 0;
  mas[12] = 1;
  mas[13] = 0;
  mas[14] = 1;
  mas[15] = 0;
  int a;
  cin >> a;
  cout << mas[a - 1];
}
