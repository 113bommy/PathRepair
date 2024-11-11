#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int s11 = s1.size();
  int s22 = s2.size();
  int i = 0;
  int j = 0;
  while (s22--) {
    if (s2[i] == s1[j]) {
      j++;
      i++;
    } else
      i++;
  }
  cout << j + 1 << endl;
}
