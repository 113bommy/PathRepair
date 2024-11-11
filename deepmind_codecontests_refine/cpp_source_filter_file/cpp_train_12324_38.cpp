#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  cin >> n;
  char str[3];
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str[1] == '+')
      x++;
    else
      x--;
  }
  cout << x;
  return 0;
}
