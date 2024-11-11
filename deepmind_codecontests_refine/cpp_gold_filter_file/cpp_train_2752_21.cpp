#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, ans = 0, rec = 0;
  while (n--) {
    cin >> a;
    if (a == -1) {
      if (rec <= 0) {
        ans++;
      } else {
        rec--;
      }
    } else {
      rec += a;
    }
  }
  cout << abs(ans);
  return 0;
}
