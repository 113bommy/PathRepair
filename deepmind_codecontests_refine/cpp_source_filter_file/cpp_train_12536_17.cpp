#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1)
      tmp++;
    else
      ans += tmp;
  }
  cout << ans;
}
