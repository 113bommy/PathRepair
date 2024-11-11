#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char str[n + 1];
  str[n] = 0;
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0)
      str[i] = 'a';
    else if (i % 4 == 1)
      str[i] = 'a';
    else if (i % 4 == 2)
      str[i] = 'b';
    else if (i % 4 == 3)
      str[i] = 'c';
  }
  cout << str << endl;
}
