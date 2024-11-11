#include <bits/stdc++.h>
using namespace std;
int main() {
  string name, lastName, s1;
  cin >> name >> lastName;
  s1 += name[0];
  for (int i = 1; i < name.length(); i++) {
    if (name[i] > lastName[0]) {
      break;
    }
    s1 += name[i];
  }
  cout << s1 << lastName[0] << endl;
  return 0;
}
