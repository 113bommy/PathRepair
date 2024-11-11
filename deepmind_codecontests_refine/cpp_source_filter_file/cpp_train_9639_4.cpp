#include <bits/stdc++.h>
using namespace std;
int n, m;
bool check(int x) {
  if (x) {
    if (n >= 2 && m >= 2) {
      n -= 2;
      m -= 2;
      return true;
    } else if (n >= 1 && m >= 12) {
      n -= 1;
      m -= 12;
      return true;
    } else if (n >= 0 && m >= 22) {
      m -= 24;
      return false;
    }
    return false;
  } else {
    if (n >= 0 && m >= 22) {
      m -= 22;
      return true;
    } else if (n >= 1 && m >= 12) {
      n -= 1;
      m -= 12;
      return true;
    } else if (n >= 2 && m >= 2) {
      n -= 2;
      m -= 2;
      return true;
    }
    return false;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int x = 1;
  while (check(x)) {
    x = 1 - x;
  }
  if (!x)
    cout << "Ciel" << endl;
  else
    cout << "Hanako" << endl;
  return 0;
}
