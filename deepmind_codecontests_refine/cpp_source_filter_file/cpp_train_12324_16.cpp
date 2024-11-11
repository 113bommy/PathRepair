#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0;
  cin >> n;
  string str[n];
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < n; i++) {
    if (str[i] == "++x" || str[i] == "x++")
      a = a + 1;
    else
      a = a - 1;
  }
  cout << a << endl;
  return 0;
}
