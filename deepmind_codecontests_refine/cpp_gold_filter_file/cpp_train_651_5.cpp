#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 4 * n;
    while (n--) {
      cout << cnt << " ";
      cnt -= 2;
    }
    cout << '\n';
  }
  return 0;
}
