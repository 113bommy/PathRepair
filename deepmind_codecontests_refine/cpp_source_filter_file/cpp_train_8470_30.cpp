#include <bits/stdc++.h>
using namespace std;
bool distinct(int n) {
  set<int> a;
  int i, c = 0;
  while (n > 0) {
    int d = n % 10;
    a.insert(d);
    n /= 10;
  }
  int l = a.size();
  for (int i = 0; i <= l - 1; i++) {
    c++;
  }
  if (c == 4) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int y;
  cin >> y;
  for (int i = y; i <= 9000; i++) {
    if (i > y) {
      if (distinct(i)) {
        cout << i;
        break;
      }
    }
  }
  return 0;
}
