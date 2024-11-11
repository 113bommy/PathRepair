#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    int x, ans;
    ans = 1;
    for (int i = 1; i < 20; i++) {
      ans = ans + pow(2, i);
      if ((n % ans) == 0) {
        x = (n / ans);
        cout << x << endl;
        break;
      } else {
        continue;
      }
    }
  }
}
