#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  while (n != 0) {
    if (n % 8 == 1) cnt++;
    n /= 8;
  }
  cout << cnt;
}
