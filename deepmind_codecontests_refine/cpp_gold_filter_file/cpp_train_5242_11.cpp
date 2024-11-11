#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  a[1] = 1;
  a[2] = 3;
  a[3] = 5;
  a[4] = 3;
  a[5] = 3;
  int cnt = 5;
  for (int i = 6; i <= 100; i++) {
    if (i <= ((cnt * cnt) + 1) / 2) {
      a[i] = cnt;
    } else {
      cnt += 2;
      a[i] = cnt;
    }
  }
  int n;
  cin >> n;
  cout << a[n];
}
