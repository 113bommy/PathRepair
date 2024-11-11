#include <bits/stdc++.h>
using namespace std;
const int nMax = 105;
vector<int> a(nMax, 0);
int n, ans = 1e8;
inline int func(int v) {
  int result = 0, res = 0;
  for (int j = 1; j <= n; j++) {
    res = 0;
    res += abs(j - v);
    res += abs(j - 1);
    res += abs(v - 1);
    res *= 2;
    res *= a[j];
    result += res;
  }
  return result;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    ans = min(ans, func(i));
  }
  cout << ans << endl;
  return 0;
}
