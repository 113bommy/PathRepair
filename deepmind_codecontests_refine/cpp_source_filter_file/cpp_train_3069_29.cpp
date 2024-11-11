#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 8; i++) {
    cin >> str;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] == 'Q') sum1 += 9;
      if (str[j] == 'R') sum1 += 5;
      if (str[j] == 'B' || str[i] == 'K') sum1 += 3;
      if (str[j] == 'P') sum1++;
      if (str[j] == 'q') sum2 += 9;
      if (str[j] == 'r') sum2 += 5;
      if (str[j] == 'b' || str[i] == 'k') sum2 += 3;
      if (str[j] == 'p') sum2++;
    }
  }
  if (sum1 == sum2)
    cout << "Draw" << endl;
  else if (sum1 > sum2) {
    cout << "White" << endl;
  } else
    cout << "Black" << endl;
  return 0;
}
