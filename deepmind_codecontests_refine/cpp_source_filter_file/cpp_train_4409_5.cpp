#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0, c[3], d[3], k = 0;
  string l;
  cin >> a >> b;
  int ansi, ansj;
  for (int i = 0; i < a; i++) {
    cin >> l;
    for (int j = 0; j < b; j++) {
      if (l[j] == '*') {
        c[k] = i;
        d[k] = j;
        k++;
      }
    }
  }
  if (c[0] == c[1]) {
    ansi = c[2];
  } else if (c[0] == c[2]) {
    ansi = c[1];
  } else {
    ansi = c[0];
  }
  if (d[0] == d[1]) {
    ansj = d[2];
  } else if (d[0] == d[2]) {
    ansj = d[1];
  } else {
    ansj = d[0];
  }
  cerr << ansi + 1 << " " << ansj + 1;
}
