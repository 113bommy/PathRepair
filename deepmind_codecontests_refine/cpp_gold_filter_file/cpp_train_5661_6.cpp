#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0, i;
  string mot;
  cin >> mot;
  i = 0;
  while (i < mot.size()) {
    if (mot[i] == '0') {
      mot.erase(mot.begin() + i);
      cout << mot;
      return 0;
    }
    i++;
  }
  mot.erase(mot.begin());
  cout << mot;
  return 0;
}
