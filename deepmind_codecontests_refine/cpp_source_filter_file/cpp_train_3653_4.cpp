#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  cin >> a >> b >> x;
  string s = "";
  int i, c, d;
  char p, q;
  if (a > b) {
    c = a;
    d = b;
    p = '0';
    q = '1';
  } else {
    c = b;
    d = a;
    p = '1';
    q = '0';
  }
  int f = 0;
  int count = 0;
  int count2 = 0;
  for (i = x; i > 0; i--) {
    if (f == 0) {
      s += p;
      count2++;
      f = 1;
    } else {
      s += q;
      count++;
      f = 0;
    }
  }
  if (x % 2 == 1) {
    for (i = count; i < d; i++) {
      s += q;
    }
    for (i = count2; i < c; i++) {
      s += p;
    }
  } else {
    for (i = count2; i < c; i++) {
      s += p;
    }
    for (i = count; i < d; i++) {
      s += q;
    }
  }
  cout << s << endl;
}
