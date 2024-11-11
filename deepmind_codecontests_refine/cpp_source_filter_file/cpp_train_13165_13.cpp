#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char c2 = s[0], c1 = s[1];
  int mas[10] = {7, 2, 3, 3, 3, 2, 5, 1, 2, 2};
  cout << mas[c1 - '0'] * mas[c2 - '0'] << endl;
  return 0;
}
