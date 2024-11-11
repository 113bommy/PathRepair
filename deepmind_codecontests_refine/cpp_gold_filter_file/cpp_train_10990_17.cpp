#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[13];
  a[0] = 0;
  a[1] = 31;
  a[2] = 28;
  a[3] = 31;
  a[4] = 30;
  a[5] = 31;
  a[6] = 30;
  a[7] = 31;
  a[8] = 31;
  a[9] = 30;
  a[10] = 31;
  a[11] = 30;
  a[12] = 31;
  int cnt = 1;
  int x = a[n];
  for (int i = 1; i <= x; i++) {
    if (k == 8) {
      k = 1;
      cnt++;
    }
    k++;
  }
  cout << cnt << endl;
}
