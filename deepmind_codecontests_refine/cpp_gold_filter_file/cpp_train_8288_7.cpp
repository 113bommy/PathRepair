#include <bits/stdc++.h>
using namespace std;
bool order(char str[], char str1[], char str2[]) {
  int i;
  int j;
  int len = strlen(str), len1 = strlen(str1), len2 = strlen(str2);
  for (i = 0; i < len; ++i) {
    for (j = 0; j < len1; ++j)
      if (str[i + j] != str1[j]) break;
    if (j == len1)
      for (i += len1; i < len; ++i) {
        for (j = 0; j < len2; ++j)
          if (str[i + j] != str2[j]) break;
        if (j == len2) return true;
      }
  }
  return false;
}
void reverse(char st1[], char st2[]) {
  for (int i = 0; i < strlen(st1); ++i) st2[i] = st1[strlen(st1) - i - 1];
  st2[strlen(st1)] = '\0';
}
int main() {
  char st1[200], st2[200], st[110000], rst[110000];
  cin.get(st, 110000);
  cin.get();
  cin.get(st1, 200);
  cin.get();
  cin.get(st2, 200);
  reverse(st, rst);
  if (order(st, st1, st2) && order(rst, st1, st2))
    cout << "both" << endl;
  else if (order(st, st1, st2))
    cout << "forward" << endl;
  else if (order(rst, st1, st2))
    cout << "backward" << endl;
  else
    cout << "fantasy" << endl;
  return 0;
}
