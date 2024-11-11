#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int b, d;
  long long int a;
  long long int cur = 0;
  cin >> n >> b >> d;
  int ans = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a;
    if (a > b) {
      cur += a;
      if (cur > d) {
        ans++;
        cur = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
