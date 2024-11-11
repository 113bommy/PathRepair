#include <bits/stdc++.h>
using namespace std;
char s[2000000];
int main() {
  cin >> s;
  for (int i = 0; s[i]; i++) {
    int c = s[i];
    int f = 255 - s[i];
    string temp = "";
    for (int j = 0; j < f; j++) temp += "...";
    temp += ".X.";
    for (int j = 0; j < c; j++) temp += "...";
    temp += "\n";
    for (int j = 0; j < f; j++) temp += ".X.";
    temp += ".X.";
    for (int j = 0; j < c; j++) temp += ".X.";
    temp += "\n";
    for (int j = 0; j < 256; j++) temp += "...";
    cout << temp << endl;
  }
  return 0;
}
