#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MAXN = 1000100;
int main() {
  int a, b;
  scanf("%d:%d", &a, &b);
  if (a == 0 && b == 0) cout << 0;
  if (a == 0 && b >= 1) cout << 60 + 10 - b;
  if (a == 1 && b <= 10) cout << 10 - b;
  if (a == 1 && b > 10) cout << 60 + 20 - b;
  if (a == 2 && b <= 20) cout << 20 - b;
  if (a == 2 && b > 20) cout << 60 + 30 - b;
  if (a == 3 && b <= 30) cout << 30 - b;
  if (a == 3 && b > 30) cout << 60 + 40 - b;
  if (a == 4 && b <= 40) cout << 40 - b;
  if (a == 4 && b > 40) cout << 60 + 50 - b;
  if (a == 5 && b <= 50) cout << 50 - b;
  if ((a == 5 && b > 40)) cout << 60 * 4 + 61 - b;
  if (a == 6) cout << 60 * 3 + 61 - b;
  if (a == 7) cout << 60 * 2 + 61 - b;
  if (a == 8) cout << 60 + 61 - b;
  if (a == 9) cout << 61 - b;
  if (a == 10 && b <= 1)
    cout << 1 - b;
  else if (a == 10)
    cout << 60 + 11 - b;
  if (a == 11 && b <= 11)
    cout << 11 - b;
  else if (a == 11)
    cout << 60 + 21 - b;
  if (a == 12 && b <= 21)
    cout << 21 - b;
  else if (a == 12)
    cout << 60 + 31 - b;
  if (a == 13 && b <= 31)
    cout << 31 - b;
  else if (a == 13)
    cout << 60 + 41 - b;
  if (a == 14 && b <= 41)
    cout << 41 - b;
  else if (a == 14)
    cout << 60 + 51 - b;
  if (a == 15 && b <= 51)
    cout << 51 - b;
  else if (a == 15)
    cout << 60 * 5 + 2 - b;
  if (a == 16) cout << 60 * 4 + 2 - b;
  if (a == 17) cout << 60 * 3 + 2 - b;
  if (a == 18) cout << 60 * 2 + 2 - b;
  if (a == 19) cout << 60 + 2 - b;
  if (a == 20 && b <= 2)
    cout << 2 - b;
  else if (a == 20)
    cout << 60 + 12 - b;
  if (a == 21 & b <= 12)
    cout << 12 - b;
  else if (a == 21)
    cout << 60 + 22 - b;
  if (a == 22 && b <= 22)
    cout << 22 - b;
  else if (a == 22)
    cout << 60 + 32 - b;
  if (a == 23 && b <= 32)
    cout << 32 - b;
  else if (a == 23)
    cout << 60 - b;
  return 0;
}
