#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int x, y = 10001, z = -1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x < y) {
      y = x;
      a++;
    }
    if (x > z) {
      z = x;
      a++;
    }
  }
  cout << a - 2 << endl;
  return 0;
}
