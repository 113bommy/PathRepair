#include <bits/stdc++.h>
using namespace std;
int main() {
  int num = 0;
  cin >> num;
  int ans = 0;
  ans = num / 100;
  num %= 100;
  ans += num / 20;
  num %= 20;
  ans += num / 10;
  num %= 10;
  ans += num / 5;
  num %= 5;
  ans += num / 5;
  cout << ans << "\n";
  return 0;
}
