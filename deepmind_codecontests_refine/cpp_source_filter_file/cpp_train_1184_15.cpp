#include <bits/stdc++.h>
using namespace std;
string FILE_NAME = "testcase.B";
string NAME;
string itos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
int main() {
  long long n, k;
  cin >> n >> k;
  if (n == 1LL) {
    cout << 0 << endl;
  } else if (n <= k) {
    cout << 1 << endl;
  } else if (n > k * (k - 1LL) / 2LL + 1LL) {
    cout << -1 << endl;
  } else {
    long long lo = 0LL;
    long long hi = k - 1LL;
    while (lo < hi) {
      long long mid = (lo + hi) / 2LL;
      if (k * (k - 1LL) / 2LL + 1LL - (k - mid) * (k - mid + 1LL) / 2LL < n) {
        lo = mid + 1LL;
      } else {
        hi = mid;
      }
    }
    cout << hi << endl;
  }
  return 0;
}
