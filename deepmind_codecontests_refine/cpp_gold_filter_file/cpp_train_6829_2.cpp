#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long ws = k + 1;
  long long w = n / ws;
  w *= ws;
  if (2LL * w > n) {
    w = (n / 2LL);
    w -= w % ws;
  }
  cout << (w / ws) << " " << (w / ws) * k << " " << n - w << endl;
  return 0;
}
