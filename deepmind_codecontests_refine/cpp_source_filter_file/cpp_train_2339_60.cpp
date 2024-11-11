#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0;
  char s1[10], s2[10], s3[10];
  cin >> s1 >> s2 >> s3;
  if (strlen(s1) == 5) {
    if (strlen(s2) == 4 && strlen(s3) == 4)
      cout << "F";
    else
      c++;
  } else if (strlen(s1) == 4) {
    if (strlen(s2) == 7 && strlen(s3) == 7)
      cout << "F";
    else
      c++;
  } else {
    if (strlen(s2) == 5 && strlen(s3) == 5)
      cout << "F";
    else
      c++;
  }
  if (strlen(s2) == 5) {
    if (strlen(s1) == 4 && strlen(s3) == 4)
      cout << "M";
    else
      c++;
  } else if (strlen(s2) == 4) {
    if (strlen(s1) == 7 && strlen(s3) == 7)
      cout << "M";
    else
      c++;
  } else {
    if (strlen(s1) == 5 && strlen(s3) == 5)
      cout << "M";
    else
      c++;
  }
  if (strlen(s3) == 5) {
    if (strlen(s2) == 4 && strlen(s1) == 4)
      cout << "S";
    else
      c++;
  } else if (strlen(s3) == 4) {
    if (strlen(s2) == 7 && strlen(s1) == 7)
      cout << "S";
    else
      c++;
  } else {
    if (strlen(s2) == 5 && strlen(s1) == 5)
      cout << "S";
    else
      c++;
  }
  if (c == 3) cout << "?";
  return (0);
}
