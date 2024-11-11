#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, value, l, p1, p2;
  char s[4], a;
  cin >> n;
  p1 = -2000000000;
  p2 = 2000000000;
  ;
  for (i = 1; i <= n; i++) {
    cin >> s;
    cin >> value;
    cin >> a;
    l = strlen(s);
    if (a == 'Y' && l == 2 && s[0] == '>') {
      if (p1 < value) {
        p1 = value;
      }
    } else if (a == 'Y' && l == 1 && s[0] == '>') {
      if (p1 < (value + 1)) {
        p1 = value + 1;
      }
    } else if (a == 'Y' && l == 2 && s[0] == '<') {
      if (p2 > (value)) {
        p2 = value;
      }
    } else if (a == 'Y' && l == 1 && s[0] == '<') {
      if (p2 > (value - 1)) {
        p2 = value - 1;
      }
    } else if (a == 'N' && l == 2 && s[0] == '>') {
      if (p2 > (value - 1)) {
        p2 = value - 1;
      }
    } else if (a == 'N' && l == 1 && s[0] == '>') {
      if (p2 > (value)) {
        p2 = value;
      }
    } else if (a == 'N' && l == 2 && s[0] == '<') {
      if (p1 < (value + 1)) {
        p1 = value + 1;
      }
    } else if (a == 'N' && l == 1 && s[0] == '<') {
      if (p1 < (value)) {
        p1 = value;
      }
    }
  }
  if (p1 == p2) {
    cout << p1;
  } else if (p1 < p2) {
    cout << p1 + 1;
  } else {
    cout << "Impossible";
  }
}
