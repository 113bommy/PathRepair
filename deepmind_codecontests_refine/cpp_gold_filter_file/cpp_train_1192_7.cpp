#include <bits/stdc++.h>
using namespace std;
int main() {
  string a = "qwertyuiopasdfghjkl;zxcvbnm,./";
  string i;
  char c;
  cin >> c;
  cin >> i;
  if (c == 'R') {
    int l = i.size();
    for (int j = 0; j < l; j++) {
      char k = i[j];
      cout << a[(a.find(k)) - 1];
    }
  } else if (c == 'L') {
    int l = i.size();
    for (int j = 0; j < l; j++) {
      char k = i[j];
      cout << a[(a.find(k)) + 1];
    }
  }
}
