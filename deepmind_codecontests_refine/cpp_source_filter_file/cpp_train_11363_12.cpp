#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, ans = 1;
  cin >> n;
  for (i = 2; i < n; i++) {
    ans += i * (i + 1);
  }
  cout << ans << endl;
  return 0;
}
