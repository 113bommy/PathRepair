#include <bits/stdc++.h>
using namespace std;
string str;
void display() {
  cin >> str;
  int num = 0;
  for (int j = 0, i = 0; j < (int)str.length(); j++)
    if (str[j] == '>') {
      string tmp = "";
      bool isclose = false;
      for (int k = i; k <= j; k++) {
        if (str[k] == '/') isclose = true;
        tmp += str[k];
      }
      if (isclose) num--;
      for (int k = 0; k < num; k++) printf(" ");
      cout << tmp << endl;
      if (!isclose) num++;
      i = j + 1;
    }
}
int main() {
  display();
  return 0;
}
