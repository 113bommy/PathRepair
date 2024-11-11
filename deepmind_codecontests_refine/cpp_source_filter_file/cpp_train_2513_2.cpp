#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  int ans = 0;
  cin >> n;
  int ch;
  while (n--) {
    cin >> ch;
    if (ch % 2 == 0) {
      ans += i;
    }
    i++;
  }
  cout << ans << "\n";
}
