#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b = 0, c = 0;
  cin >> a;
  if (a % 10 == 0) b = 2;
  if (a % 10 == 1) b = 7;
  if (a % 10 == 2) b = 2;
  if (a % 10 == 3) b = 3;
  if (a % 10 == 4) b = 3;
  if (a % 10 == 5) b = 4;
  if (a % 10 == 6) b = 2;
  if (a % 10 == 7) b = 5;
  if (a % 10 == 8) b = 1;
  if (a % 10 == 9) b = 2;
  if (a / 10 == 0) c = 2;
  if (a / 10 == 1) c = 7;
  if (a / 10 == 2) c = 2;
  if (a / 10 == 3) c = 3;
  if (a / 10 == 4) c = 3;
  if (a / 10 == 5) c = 4;
  if (a / 10 == 6) c = 2;
  if (a / 10 == 7) c = 5;
  if (a / 10 == 8) c = 1;
  if (a / 10 == 9) c = 2;
  cout << b * c;
}
