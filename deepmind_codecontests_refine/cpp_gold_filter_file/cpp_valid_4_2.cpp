#include <bits/stdc++.h>
using namespace std;
void refresh() {}
int main() {
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    refresh();
    long long n, ans1, ans2;
    cin >> n;
    ans1 = n - 1;
    ans2 = ans1 / 2;
    cout << ans2 << ' ' << ans1 << endl;
  }
  return 0;
}
