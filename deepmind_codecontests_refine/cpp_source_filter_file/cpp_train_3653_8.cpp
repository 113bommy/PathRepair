#include <bits/stdc++.h>
using namespace std;
long long t = 1;
void solve() {
  int a, b, x;
  cin >> a >> b >> x;
  string s = "";
  x = x - 1;
  if (x == 0) {
    while (b) {
      s += '1';
      b--;
    }
    while (a) {
      s += '0';
      a--;
    }
    cout << s;
    return;
  }
  int flag;
  if (a > b) {
    s += '0';
    flag = 1;
    a--;
  } else {
    s += '1';
    flag = 0;
    b--;
  }
  for (int i = 0; i < x; i++) {
    if (flag == 0) {
      if (a) {
        s += '0';
        a--;
      }
      flag = 1;
    } else {
      if (b) {
        s += '1';
        b--;
      }
      flag = 0;
    }
  }
  if (flag == 0) {
    while (a) {
      s += '0';
      a--;
    }
    while (b) {
      s += '1';
      b--;
    }
  } else {
    while (b) {
      s += '1';
      b--;
    }
    while (a) {
      s += '0';
      a--;
    }
  }
  cout << s;
}
int main() {
  int i;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) solve();
  return 0;
}
