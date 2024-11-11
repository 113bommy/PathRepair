#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c, d, e, f;
  cin >> t >> a >> b >> c >> d;
  string s;
  cin >> s;
  if (a > c) {
    e = 1;
  } else {
    e = 0;
  }
  if (b > d) {
    f = 1;
  } else {
    f = 0;
  }
  int i = 0;
  while (i < s.size() && (a != c || b != d)) {
    if (s[i] == 'S' && f == 1 && b != d) {
      b -= 1;
    }
    if (s[i] == 'W' && e == 1 && a != c) {
      a -= 1;
    }
    if (s[i] == 'N' && f == 0 && b != d) {
      b += 1;
    }
    if (s[i] == 'E' && e == 0 && a != c) {
      a += 1;
    }
    i++;
  }
  if (i == s.size() && a != c && b != d) {
    cout << -1 << endl;
  } else {
    cout << i << endl;
  }
}
