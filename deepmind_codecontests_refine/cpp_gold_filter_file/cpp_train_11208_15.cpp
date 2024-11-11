#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, cnt = 0, del = 0;
  char c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == 'x') {
      cnt++;
    } else {
      if (cnt > 2) {
        del += cnt - 2;
      }
      cnt = 0;
    }
  }
  if (cnt > 2) {
    del += cnt - 2;
  }
  cout << del << "\n";
  return 0;
}
