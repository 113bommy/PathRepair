#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, cnt = 1;
  cin >> n >> k;
  for (int i = 0; i < n - k; ++i) {
    cnt = cnt * (n - k) % 1000000007;
  }
  for (int i = 0; i < k - 1; ++i) {
    cnt = cnt * k % 1000000007;
  }
  cout << cnt << endl;
  return 0;
}
