#include <bits/stdc++.h>
using namespace std;
char a[10000000], b[10000000];
int x, y;
int main() {
  cin >> a;
  x = strlen(a);
  for (int i = x - 1; i >= 0; i--) {
    b[i] = max(b[i + 1], a[i]);
  }
  for (int i = 0; i <= x - 1; i++) {
    if (b[i] == a[i]) {
      cout << a[i];
    }
  }
  return 0;
}
