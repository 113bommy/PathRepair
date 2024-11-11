#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int cnt = 0;
  while (a) {
    if (a % 8 == 2) cnt++;
    a /= 8;
  }
  cout << cnt;
  return 0;
}
