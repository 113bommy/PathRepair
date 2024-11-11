#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, m, ans = 0;
  cin >> a >> m;
  for (int i = 0; i < m; i++) {
    ans = a % m;
    if (ans == 0) {
      cout << "Yes" << '\n';
      return 0;
    }
    a = a + ans;
  }
  cout << "No" << '\n';
  return 0;
}
