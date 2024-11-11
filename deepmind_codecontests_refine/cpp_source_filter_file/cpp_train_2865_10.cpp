#include <bits/stdc++.h>
using namespace std;
int main() {
  string w, x;
  int i, j = 0, len, l;
  cin >> w;
  cin >> x;
  l = w.length();
  len = x.length();
  for (i = 0; i < l; i++) {
    string temp = w.substr(i, len);
    if (temp == x) {
      j++;
      i = len + i;
    }
  }
  cout << j << endl;
  return 0;
}
