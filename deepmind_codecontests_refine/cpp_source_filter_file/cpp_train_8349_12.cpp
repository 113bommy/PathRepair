#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, h, m;
  cin >> n;
  while (n--) {
    cin >> h >> m;
    int ans = (23 - h) * 60 + 60 - h;
    cout << ans << endl;
  }
  return 0;
}
