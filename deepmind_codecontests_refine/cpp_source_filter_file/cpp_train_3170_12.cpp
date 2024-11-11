#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string s;
  cin >> s;
  string k;
  string z;
  int a = 1;
  int b = 0;
  for (int i = 1; i < x; i++) {
    cin >> k;
    if (k == s) {
      a++;
    } else {
      z = k;
      b++;
    }
  }
  if (a > b) {
    cout << a;
  } else
    cout << b;
}
