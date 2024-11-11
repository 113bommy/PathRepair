#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char c[101];
  scanf("%s", &c);
  string s = c;
  n = s.length();
  bool veciOdPet = false, number = false, lower = false, apper = false;
  if (n >= 5) veciOdPet = true;
  for (int i = 0; i < n; i++) {
    char ch = s[i];
    if ((ch >= 97) && (ch <= 122)) lower = true;
    if ((ch >= 65) && (ch <= 90)) apper = true;
    if ((ch >= 48) && (ch <= 57)) number = true;
  }
  if (number && apper && lower && veciOdPet)
    printf("Correct");
  else
    printf("Too weak");
  return 0;
}
