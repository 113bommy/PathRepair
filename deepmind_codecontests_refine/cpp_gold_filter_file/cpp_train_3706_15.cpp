#include <bits/stdc++.h>
using namespace std;
int p(int a) {
  int m = a / 2;
  int c = 0;
  for (int i = 2; i <= m; i++) {
    if (a % i == 0) {
      c++;
    }
  }
  if (c > 0) {
    return 0;
  } else
    return 1;
}
int main() {
  int n, m, d = 0;
  int p(int a);
  cin >> n >> m;
  if (p(n) == 1 && p(m) == 1) {
    for (int i = n + 1; i < m; i++) {
      if (p(i) == 1) {
        d++;
      }
    }
  } else {
    d++;
  }
  if (d > 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
