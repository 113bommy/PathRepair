#include <bits/stdc++.h>
using namespace std;
int main() {
  int co = 0;
  string z;
  cin >> z;
  vector<int> c(26, 0);
  int l = z.size();
  for (int i = 0; i < l; i++) {
    c[z[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    char q = 'a' + i;
    if (c[i] != 0) {
      if (c[i] % 2 == 1) co++;
    }
  }
  if (co % 2 == 0 || co == 1)
    cout << "First";
  else
    cout << "Second";
}
