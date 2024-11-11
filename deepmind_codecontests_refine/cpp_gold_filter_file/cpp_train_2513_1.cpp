#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  int ans = 0;
  cin >> n;
  char ch;
  while (n--) {
    cin >> ch;
    if (ch % 2 == 0) {
      ans += i + 1;
    }
    i++;
  }
  cout << ans << "\n";
}
