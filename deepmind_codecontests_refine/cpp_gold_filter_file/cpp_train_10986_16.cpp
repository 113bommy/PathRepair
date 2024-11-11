#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  int maxi = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = i;
    while (x > 0) {
      if (vec[x - 1] <= vec[x]) {
        maxi++;
        x--;
      } else
        break;
    }
    x = i;
    while (x < n - 1) {
      if (vec[x + 1] <= vec[x]) {
        maxi++;
        x++;
      } else
        break;
    }
    ans = max(ans, maxi + 1);
    maxi = 0;
  }
  cout << ans;
  return 0;
}
