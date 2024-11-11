#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  string str;
  cin >> str;
  int countR = 0, countG = 0, countB = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'R' && str[i + 1] != 'R') countR++;
    if (str[i] == 'B' && str[i + 1] != 'B') countB++;
    if (str[i] == 'G' && str[i + 1] != 'G') countG++;
  }
  cout << (countG + countB + countR) << "\n";
}
