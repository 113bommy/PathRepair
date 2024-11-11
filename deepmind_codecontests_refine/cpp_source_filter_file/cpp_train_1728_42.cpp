#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    ans += (i * 2 + 1) % (n + 1);
  }
  cout << ans % n;
}
