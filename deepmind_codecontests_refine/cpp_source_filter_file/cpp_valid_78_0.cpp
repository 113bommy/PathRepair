#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010;
const unsigned long long P = 13331;
int n, a[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    if ((long long)l * 2 > r) {
      ans = r - l;
    } else {
      if (r & 1)
        ans = (r - 2) / 2;
      else
        ans = (r - 1) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
