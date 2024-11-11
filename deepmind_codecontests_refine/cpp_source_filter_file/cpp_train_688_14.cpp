#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int f1 = 1, f2 = 1;
int main() {
  cin >> n;
  a[1] = 1;
  for (; f2 <= n;) {
    f2 = f1 + f2;
    f1 = f2 - f1;
    a[f2] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i])
      cout << "O";
    else
      cout << "o";
  }
}
