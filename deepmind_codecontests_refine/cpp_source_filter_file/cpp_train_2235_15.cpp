#include <bits/stdc++.h>
using namespace std;
string a, b;
int la, lb, m, f, g;
int main() {
  cin >> a >> b;
  la = (int)a.size();
  lb = (int)b.size();
  for (int i = 0; i < la; i++) {
    if (int(a[i] - '0') > m) {
      m = int(a[i] - '0');
    }
  }
  for (int i = 0; i < lb; i++) {
    if (int(b[i] - '0') > m) {
      m = int(b[i] - '0');
    }
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (lb < la) {
    for (int i = 0; i < max(la, lb) - min(la, lb); i++) {
      b += '0';
    }
  } else {
    for (int i = 0; i < max(la, lb) - min(la, lb); i++) {
      a += '0';
    }
  }
  for (int i = 0; i < max(la, lb); i++) {
    if (int(a[i] - '0') + int(b[i] - '0') + f >= m + 1) {
      g++;
      f = int(a[i] - '0') + int(b[i] - '0') + f - m;
    } else {
      g++;
      f = 0;
    }
  }
  if (f != 0) {
    cout << g + 1;
    return 0;
  }
  cout << g;
  return 0;
}
