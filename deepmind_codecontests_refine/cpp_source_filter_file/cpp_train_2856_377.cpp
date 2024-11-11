#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main(void) {
  int mas[16];
  mas[0] = 1;
  mas[1] = 1;
  mas[2] = 0;
  mas[3] = 0;
  mas[4] = 0;
  mas[5] = 0;
  mas[6] = 0;
  mas[7] = 1;
  mas[8] = 0;
  mas[9] = 0;
  mas[10] = 0;
  mas[11] = 1;
  mas[12] = 1;
  mas[13] = 1;
  mas[14] = 1;
  mas[15] = 1;
  int a;
  cin >> a;
  cout << mas[a - 1];
}
