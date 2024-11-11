#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    ans = max(ans, a);
  }
  cout << a;
  return 0;
}
