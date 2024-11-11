#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[10], str2[10], str3[10];
  cin >> str1 >> str2 >> str3;
  if (strcmp(str1, "rock") == 0)
    if (strcmp(str2, "scissors") == 0 && strcmp(str3, "scissors") == 0) {
      cout << 'F';
      return 0;
    }
  if (strcmp(str1, "scissors") == 0)
    if (strcmp(str2, "paper") == 0 && strcmp(str3, "paper") == 0) {
      cout << 'F';
      return 0;
    }
  if (strcmp(str1, "paper") == 0)
    if (strcmp(str2, "rock") == 0 && strcmp(str3, "rock") == 0) {
      cout << 'F';
      return 0;
    }
  if (strcmp(str2, "rock") == 0)
    if (strcmp(str1, "scissors") == 0 && strcmp(str3, "scissors") == 0) {
      cout << 'M';
      return 0;
    }
  if (strcmp(str2, "scissors") == 0)
    if (strcmp(str1, "paper") == 0 && strcmp(str3, "paper") == 0) {
      cout << 'M';
      return 0;
    }
  if (strcmp(str2, "paper") == 0)
    if (strcmp(str1, "rock") == 0 && strcmp(str3, "rock") == 0) {
      cout << 'M';
      return 0;
    }
  if (strcmp(str3, "rock") == 0)
    if (strcmp(str1, "scissors") == 0 && strcmp(str2, "scissors") == 0) {
      cout << 'S';
      return 0;
    }
  if (strcmp(str3, "scissors") == 0)
    if (strcmp(str1, "paper") == 0 && strcmp(str2, "paper") == 0) {
      cout << 'S';
      return 0;
    }
  if (strcmp(str3, "paper") == 0)
    if (strcmp(str1, "rock") == 0 && strcmp(str2, "rock") == 0) {
      cout << 'S';
      return 0;
    }
  cout << '?';
  return 0;
}
