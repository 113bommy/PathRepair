#include <bits/stdc++.h>
using namespace std;
char c[111];
int n;
bool f(int x) {
  if (x >= n)
    return false;
  else if (c[x] == '.')
    return false;
  else
    return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int l = 1; l < n / 4; l++) {
    for (int i = 0; i < n; i++) {
      if (f(i) && f(i + l) && f(i + l + l) && f(i + l + l + l) &&
          f(i + l + l + l + l)) {
        cout << "yes";
        exit(0);
      }
    }
  }
  cout << "no";
}
