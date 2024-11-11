#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int nm = 1, ans = 0;
  while (n--) {
    nm *= 2;
    ans += nm;
  }
  cout << ans << endl;
  return 0;
}
