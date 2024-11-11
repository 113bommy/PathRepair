#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "halfplus")
      a[i] = 1;
    else
      a[i] = -1;
  }
  long long kol = 1, ans = p / 2;
  for (int i = n - 2; i >= 0; i--) {
    ans += kol * p;
    kol *= 2;
    if (a[i] == 1) {
      kol += 1;
      ans += p / 2;
    }
  }
  cout << ans;
}
