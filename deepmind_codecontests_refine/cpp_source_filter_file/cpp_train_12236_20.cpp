#include <bits/stdc++.h>
using namespace std;
int sc1() {
  int x;
  scanf("%d", &x);
  return x;
}
long long sc2() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int main() {
  int n = sc1(), a = sc1(), b = sc1();
  int cnt = 0;
  if (b > 0) {
    for (int i = a; 1; i++) {
      cnt++;
      if (cnt == b + 1) {
        cout << ++i << endl;
        return 0;
      }
      if (i == n) i = 0;
    }
  } else if (b < 0) {
    b = -b;
    for (int i = a; 1; i--) {
      cnt++;
      if (cnt == b + 1) {
        cout << i << endl;
        return 0;
      }
      if (i == 1) i = n + 1;
    }
  } else
    cout << a << endl;
  return 0;
}
