#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int c = 0;
  int len1 = s1.size();
  int len2 = s2.size();
  for (int i = 0; i < len1; i++) {
    int j;
    for (j = 0; j < len2; j++)
      if (s1[i++] != s2[j]) break;
    if (j == len2) {
      c++;
      s1[i - 1] = '.';
    }
  }
  cout << c << endl;
}
