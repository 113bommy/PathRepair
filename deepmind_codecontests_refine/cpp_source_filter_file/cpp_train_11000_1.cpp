#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  while (tests--) {
    long long n;
    cin >> n;
    long long ans = n / 100;
    n %= 100;
    ans += n / 20;
    n %= 20;
    ans + n / 10;
    n %= 10;
    ans += n / 5;
    n %= 5;
    ans += n;
    cout << ans;
  }
  return 0;
}
