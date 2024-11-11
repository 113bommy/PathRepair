#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int b4 = 0, b7 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4') b4++;
    if (s[i] == '7') b7++;
  }
  cout << (b4 == 0 && b7 == 0 ? "-1" : (b7 > b4 ? "7" : "4"));
}
