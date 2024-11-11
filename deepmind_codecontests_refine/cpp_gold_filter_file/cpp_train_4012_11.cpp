#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int cnt = 0;
  while (a > 0 && b - 2 >= 0) {
    b -= 2;
    a += 1;
    cnt++;
    if (a > b) swap(a, b);
  }
  cout << cnt;
  return 0;
}
