#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int d[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  if (n <= 11) {
    cout << d[n] << endl;
  } else {
    long long ans = 341;
    cout << ans + (long long)(n - 11) * 49 << endl;
  }
}
