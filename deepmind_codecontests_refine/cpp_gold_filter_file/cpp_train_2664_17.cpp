#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  char ch[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
  string s;
  cin >> n;
  for (i = 0, j = 0; i < n; i++) {
    s += ch[j];
    j++;
    if (j % 7 == 0) j = 3;
  }
  cout << s << endl;
  return 0;
}
