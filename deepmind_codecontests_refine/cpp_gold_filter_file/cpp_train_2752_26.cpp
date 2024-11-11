#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int main() {
  cin >> n;
  int res = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x == -1) {
      if (!cnt)
        ++res;
      else
        --cnt;
    } else
      cnt += x;
  }
  cout << res << endl;
  return 0;
}
