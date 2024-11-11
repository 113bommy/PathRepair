#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e[3003];
long long h;
int main() {
  cin >> a;
  for (b = 2; b <= a; b++) {
    if (e[b] == 0) {
      h = b;
    } else {
      continue;
    }
    while (h <= a) {
      e[h]++;
      h += b;
    }
  }
  for (b = 6; b <= a; b++) {
    if (e[b] == 2) {
      d++;
    }
  }
  cout << d;
}
