#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long cur = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x)
      cur++;
    else
      ans += cur;
  }
  cout << ans;
}
