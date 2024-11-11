#include <bits/stdc++.h>
using namespace std;
ifstream fin("A.in");
int n, x, cnt, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x == -1) {
      if (cnt == 0) {
        ++ans;
      } else
        --cnt;
    } else
      ++cnt;
  }
  cout << ans;
}
