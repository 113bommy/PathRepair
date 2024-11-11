#include <bits/stdc++.h>
using namespace std;
int f[10000000];
int na = 0;
bool funcky(int n) {
  for (int i = 0; n >= f[i]; i++) {
    if (n == f[i]) return 1;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    na++;
    f[i] = i * (i + 1) / 2;
  }
  for (int i = 0; i < na; i++) {
    if (funcky(n - f[i])) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
