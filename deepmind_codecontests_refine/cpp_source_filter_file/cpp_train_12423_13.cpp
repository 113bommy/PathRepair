#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
  cout << setprecision(9);
  cin >> s1 >> s2;
  sort(s2.begin(), s2.end());
  int j = s2.size() - 1;
  for (int i = 0; i < s1.size(); i++) {
    if (j > 0 && s1[i] < s2[j]) {
      s1[i] = s2[j];
      j--;
    }
  }
  cout << s1 << endl;
  return 0;
}
