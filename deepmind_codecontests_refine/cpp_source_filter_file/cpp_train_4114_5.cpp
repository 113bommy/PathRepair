#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[100001], str[] = ",", str1[2] = {'"'};
  long long i;
  bool start1 = 0, start2 = 0;
  bool check = 0;
  char c1[100010], c2[100010], c3[100010];
  c1[0] = '"';
  c2[0] = '"';
  c1[1] = '\0';
  c2[1] = '\0';
  cin >> c;
  long long previ = -1, presi = 0;
  while (1) {
    i = 0;
    check = false;
    while (c[presi + i] != ',' && c[presi + i] != ';' && c[presi + i] != '\0') {
      if (c[presi + i] > '9' && c[presi + i] < '0') check = true;
      c3[i] = c[presi + i];
      i++;
    }
    c3[i] = '\0';
    if (c3[0] == '0' && i > 1) check = true;
    if (check == false && i != 0) {
      if (start1 == true) strcat(c1, str);
      if (start1 == false) start1 = true;
      strcat(c1, c3);
    } else {
      if (start2 == true) strcat(c2, str);
      if (start2 == false) start2 = true;
      strcat(c2, c3);
    }
    if (c[presi + i] == '\0') break;
    previ = presi + i;
    presi = previ + 1;
  }
  strcat(c1, str1);
  strcat(c2, str1);
  if (start1 == true)
    cout << c1 << "\n";
  else
    cout << "-\n";
  if (start2 == true)
    cout << c2 << "\n";
  else
    cout << "-\n";
}
