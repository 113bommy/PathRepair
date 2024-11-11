#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string ans;
  while (n) {
    n--;
    ans += 'a' + n % 26;
    n /= 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
