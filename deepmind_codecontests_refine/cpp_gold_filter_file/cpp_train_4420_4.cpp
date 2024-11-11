#include <bits/stdc++.h>
using namespace std;
int main() {
  set<char> strw;
  char m[1005];
  cin.getline(m, 1005, '\n');
  for (int i = 0; i < strlen(m); i++)
    if (m[i] >= 'a' && m[i] <= 'z') strw.insert(m[i]);
  cout << strw.size() << endl << endl;
  return 0;
}
