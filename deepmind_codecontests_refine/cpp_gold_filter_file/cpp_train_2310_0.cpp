#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char k = s[0];
  cout << "Mike \n";
  for (int i = 1; i < s.size(); i++) {
    if (s[i] < k) k = s[i];
    if (s[i] == k)
      cout << "Mike \n";
    else
      cout << "Ann \n";
  }
  return 0;
}
