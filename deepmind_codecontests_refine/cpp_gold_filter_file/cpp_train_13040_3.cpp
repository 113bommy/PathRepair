#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  int candy[10000];
  int oran[10000];
  for (int i = 0; i < n; i++) {
    cin >> a;
    int cmin = 1000000000;
    int omin = 1000000000;
    for (int j = 0; j < a; j++) {
      cin >> candy[j];
      cmin = min(cmin, candy[j]);
    }
    for (int j = 0; j < a; j++) {
      cin >> oran[j];
      omin = min(omin, oran[j]);
    }
    long long ans = 0;
    for (int j = 0; j < a; j++) {
      ans += max(candy[j] - cmin, oran[j] - omin);
    }
    cout << ans << "\n";
  }
}
