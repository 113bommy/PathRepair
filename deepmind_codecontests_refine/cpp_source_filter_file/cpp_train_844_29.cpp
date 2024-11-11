#include <bits/stdc++.h>
#pragma hdrstop
#pragma argsused
using namespace std;
int n, i;
int main() {
  cin >> n;
  for (i = 1; i <= (n / 4); i++) {
    cout << "abcd";
  }
  n = n % 4;
  if (n = 1) {
    cout << "a";
  }
  if (n = 2) {
    cout << "ab";
  }
  if (n = 3) {
    cout << "abc";
  }
  return 0;
}
