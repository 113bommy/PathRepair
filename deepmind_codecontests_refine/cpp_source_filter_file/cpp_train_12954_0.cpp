#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, k;
  cin >> n >> k;
  int pairs = n / 2;
  if (n == 1 && k == 0) {
    cout << 1;
    return 0;
  }
  if (n == 1 && k >= n) {
    cout << -1;
    return 0;
  }
  if (pairs > k) {
    cout << -1;
    return 0;
  }
  pairs--;
  long long st = 1000000000;
  for (int i = 1; i <= pairs; i++) {
    cout << st << " ";
    cout << st - 1 << " ";
    st -= 2;
  }
  cout << (long long)(k - pairs) << " " << (long long)(k - pairs) << " ";
  if (n % 2 == 1) cout << (k - pairs);
  return 0;
}
