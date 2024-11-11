#include <bits/stdc++.h>
using namespace std;
string s[3] = {"scissors", "paper", "rock"};
int gao(string s1) {
  for (int i = 0; i < 3; i++) {
    if (s1 == s[i]) return i;
  }
}
char ch[3] = {'F', 'M', 'S'};
int main() {
  string nam[3];
  for (int i = 0; i < 3; i++) {
    cin >> nam[i];
  }
  for (int i = 0; i < 3; i++) {
    if ((gao(nam[i]) + 1 % 3) == gao(nam[i + 1 % 3]) &&
        gao(nam[i + 1 % 3]) == gao(nam[i + 2 % 3])) {
      cout << ch[i] << endl;
      return 0;
    }
  }
  cout << "?" << endl;
  return 0;
}
