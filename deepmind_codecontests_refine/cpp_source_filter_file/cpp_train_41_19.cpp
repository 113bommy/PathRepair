#include <bits/stdc++.h>
using namespace std;
int n;
char c[10];
string fac(int x) {
  string s = "";
  while (x) {
    s = c[x % n] + s;
    x /= n;
  }
  return s;
}
int main() {
  for (int i = 0; i < 10; i++) c[i] = '0' + i;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      cout << fac(i * j);
    }
    printf("\n");
  }
}
