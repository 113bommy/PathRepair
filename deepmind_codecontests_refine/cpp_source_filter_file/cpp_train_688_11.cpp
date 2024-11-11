#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  cin >> n;
  string s;
  for (i = (0); i < (n); i++) s = s + 'O';
  int a = 1, b = 1;
  s[a - 1] = 'o';
  s[b - 1] = 'o';
  while (b < n) {
    int temp = a + b;
    a = b;
    b = temp;
    s[b - 1] = 'o';
  }
  cout << s;
  return 0;
}
