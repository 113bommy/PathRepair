#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b;
  int ans = 0;
  cin >> a >> b;
  while (a < b) {
    a = a * 3;
    b = b * 2;
    ans++;
  }
  cout << ans;
}
