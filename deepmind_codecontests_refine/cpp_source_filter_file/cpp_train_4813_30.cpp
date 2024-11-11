#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, a, b, c, ans, A, B, C;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    ans = N;
    for (int i = 1; i <= 10000; i++)
      for (int j = i; j <= 10000; j += i)
        for (int k = j; k <= 10000; k += j)
          if (abs(i - a) + abs(j - b) + abs(k - c) < ans) {
            ans = abs(i - a) + abs(j - b) + abs(k - c);
            A = i;
            B = j;
            C = k;
          }
    cout << ans << endl << A << " " << B << " " << C << endl;
  }
  return 0;
}
