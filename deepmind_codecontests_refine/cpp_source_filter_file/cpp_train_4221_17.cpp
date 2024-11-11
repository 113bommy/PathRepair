#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  while (n) {
    if (n % 16 == 1) cnt++;
    n /= 16;
  }
  cout << cnt;
  return 0;
}
