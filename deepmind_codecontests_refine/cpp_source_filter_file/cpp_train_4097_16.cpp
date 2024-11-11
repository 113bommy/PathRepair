#include <bits/stdc++.h>
using namespace std;
char a[10000000], b[10000000];
int x, t;
int main() {
  cin >> a;
  x = strlen(a);
  t = 0;
  for (int i = x - 1; i >= 0; i--) {
    if (a[i] > b[t]) b[++t] = a[i];
  }
  for (int i = t; i; i--) {
    cout << b[i];
  }
  return 0;
}
