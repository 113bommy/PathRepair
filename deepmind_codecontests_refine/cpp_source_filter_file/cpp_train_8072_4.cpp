#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int n, sum1, sum2, cnt1, cnt2;
  while (cin >> n) {
    sum1 = sum2 = 0;
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n;
    while (l < r) {
      if (cnt1 <= cnt2)
        sum1++, cnt1 += a[l++];
      else
        sum2++, cnt2 += a[r--];
    }
    cout << sum1 << ' ' << sum2 << endl;
  }
  return 0;
}
