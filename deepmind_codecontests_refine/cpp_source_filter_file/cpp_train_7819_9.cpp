#include <bits/stdc++.h>
using namespace std;
struct Node {
  int num, ma;
} a[200010];
int main() {
  int n;
  cin >> n;
  int ma = 0;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    a[i].num = t;
    while (t--) {
      int temp;
      cin >> temp;
      a[i].ma = max(a[i].ma, temp);
    }
    ma = max(ma, a[i].ma);
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (ma - a[i].ma) * a[i].num;
  }
  cout << ans << endl;
}
