#include <bits/stdc++.h>
using namespace std;
ifstream in("in.txt");
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 1; i <= a; i++) {
    if (i <= a && i * 2 <= b && i * 4 <= c) {
      ans = i + 2 * i + 4 * i;
    }
  }
  cout << ans;
  return 0;
}
