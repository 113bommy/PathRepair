#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
  cin >> s1 >> s2;
  if (s1 >= s2) {
    cout << "No such string";
    return 0;
  }
  s1[s1.size() - 1]++;
  for (int i = s1.size() - 1; i >= 0; i--) {
    if (s1[i] > 'z') {
      s1[i] -= 'z' - 'a';
      if (i == 0) {
        cout << "a";
        continue;
      }
      s1[i - 1]++;
    } else {
      break;
    }
  }
  if (s1 == s2) {
    cout << "No such string";
    return 0;
  }
  cout << s1;
  return 0;
}
