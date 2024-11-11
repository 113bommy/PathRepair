#include <bits/stdc++.h>
using namespace std;
long long n, k, ans1 = 1, ans2 = 1;
string st;
int main() {
  cin >> n >> k;
  for (int i = 0; i < k - 1; i++) {
    ans1 = (ans1 * k) % 1000000007;
  }
  for (int i = 0; i < n - k; i++) {
    ans2 = (ans2 * (n - k)) % 1000000007;
  }
  ans1 = (ans1 * ans2) % 1000000007;
  cout << ans1 << endl;
  return 0;
}
