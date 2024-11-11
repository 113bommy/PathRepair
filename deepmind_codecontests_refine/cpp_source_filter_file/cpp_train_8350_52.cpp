#include <bits/stdc++.h>
using namespace std;
void check(int a, int b) {
  int hour = 24 - (a + 1);
  int min = 60 - b;
  int ans = (hour * 60) + min;
  cout << ans;
}
int main() {
  int n;
  cin >> n;
  int a, b;
  while (n--) {
    cin >> a >> b;
    check(a, b);
  }
  return 0;
}
