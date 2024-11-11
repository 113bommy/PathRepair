#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int n, k, x, t;
string s;
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  int mx = v[n - 1];
  long long ans = mx;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] >= mx) {
      mx--;
      ans += mx;
      if (mx == 0) break;
    } else {
      ans += v[i];
      mx = v[i];
    }
  }
  cout << ans << endl;
  return 0;
}
