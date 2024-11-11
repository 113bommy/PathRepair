#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, cnt = 0;
  cin >> a;
  while (a) {
    cnt += a & 1;
    a >>= 3;
  }
  cout << cnt << endl;
  return 0;
}
