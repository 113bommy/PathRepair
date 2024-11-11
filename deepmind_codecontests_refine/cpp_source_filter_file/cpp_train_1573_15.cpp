#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  if (n == 0 || n == 1) {
    ans = n;
    cout << ans;
  } else {
    ans = (int)(1 + log2(n + 1));
    cout << ans;
  }
  return 0;
}
