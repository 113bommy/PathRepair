#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int One7Two4 = 0, One4Two7 = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[i])
      continue;
    else if (s1[i] == '7' && s2[i] == '4')
      One7Two4++;
    else if (s1[i] == '4' && s2[i] == '7')
      One4Two7++;
  }
  int x = min(One4Two7, One7Two4);
  One4Two7 -= x;
  One7Two4 -= x;
  cout << One4Two7 + One7Two4 + x << "\n";
  return 0;
}
