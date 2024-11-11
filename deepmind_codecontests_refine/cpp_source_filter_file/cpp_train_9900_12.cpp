#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n >> k;
  long long o = max(1ll, k - n);
  long long p = k / 2ll;
  cout << max(0ll, p - o + 1) << endl;
  return 0;
}
