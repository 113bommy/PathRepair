#include <bits/stdc++.h>
using namespace std;
void res() {
  int n;
  cin >> n;
  n -= 2;
  string l, s, answ = "";
  cin >> l;
  if (n == 1) {
    cout << 'a' << l;
    return;
  }
  bool f = false;
  for (int i = 1; i < n; i++) {
    cin >> s;
    answ += l[0];
    if (l[1] != s[0]) {
      answ += l[1];
      f = true;
    }
    l = s;
  }
  if (f) {
    cout << answ + l;
  } else {
    cout << 'a' + answ + l;
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    res();
    cout << endl;
  }
}
