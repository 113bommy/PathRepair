#include <bits/stdc++.h>
using namespace std;
int func(int n, int m) {
  for (int i = 2; i < m; i++) {
    if (m % i == 0) return 0;
  }
  int flag;
  for (int i = n + 1; i < m; i++) {
    flag = 0;
    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) return 0;
  }
  return 1;
}
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int temp = func(n, m);
  if (temp == 1)
    cout << "YES";
  else
    cout << "NO";
}
