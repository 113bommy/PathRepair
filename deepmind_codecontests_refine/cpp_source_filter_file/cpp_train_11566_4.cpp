#include <bits/stdc++.h>
using namespace std;
unsigned int n, x, l, ans, s[1001];
int main() {
  cin >> n >> l;
  ans = 0;
  s[ans] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < l) ++ans;
    ++s[ans];
    l = x;
  }
  cout << ans + 1 << endl;
  for (int i = 0; i <= ans; ++i) {
    cout << s[i] << " ";
  }
  return 0;
}
