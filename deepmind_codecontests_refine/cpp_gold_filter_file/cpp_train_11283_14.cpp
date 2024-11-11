#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long S = 0, l, r;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    S += r - l + 1;
  }
  cout << (S / k + (S % k != 0)) * k - S << endl;
  return 0;
}
