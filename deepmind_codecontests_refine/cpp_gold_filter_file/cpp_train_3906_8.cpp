#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int s, f;
  cin >> f >> s;
  int ans = s;
  for (int i = 0; i < f; ++i) {
    int a, b;
    cin >> a >> b;
    ans = max(ans, a + b);
  }
  cout << ans;
}
