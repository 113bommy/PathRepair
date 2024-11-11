#include <bits/stdc++.h>
using namespace std;
int main() {
  int Ar[4], i, j, sum = 0;
  char str[1000000];
  for (i = 1; i <= 4; i++) {
    cin >> Ar[i];
  }
  cin >> str;
  int len = strlen(str);
  for (i = 0; str[i] != '\0'; i++) {
    char y = str[i] - 48;
    int X = y;
    sum = sum + Ar[X];
  }
  cout << sum << endl;
  return 0;
}
