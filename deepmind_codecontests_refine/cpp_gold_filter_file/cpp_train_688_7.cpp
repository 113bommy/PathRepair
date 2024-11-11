#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  cin >> n;
  string s;
  for (i = (0); i < (n); i++) s = s + 'o';
  int a = 1, b = 1;
  s[a - 1] = 'O';
  s[b - 1] = 'O';
  while (b < n) {
    int temp = a + b;
    a = b;
    b = temp;
    s[b - 1] = 'O';
  }
  cout << s;
  return 0;
}
