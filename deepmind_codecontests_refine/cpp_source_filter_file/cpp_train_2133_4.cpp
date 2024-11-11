#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long A, B, n;
  cin >> A >> B >> n;
  for (int i = 0; i < n; ++i) {
    int l, t, m;
    cin >> l >> t >> m;
    if (A + (l - 1) * B > t) {
      cout << "-1\n";
    } else {
      long long ans = (t - A) / B + 1 - l + 1;
      long long left = 1, right = ans + 1;
      while (right - left > 1) {
        long long temp = (right + left) >> 1;
        if ((A + (l - 1) * B) * temp + (temp - 1) * temp * B / 2 > t * m)
          right = temp;
        else
          left = temp;
      }
      cout << left + l - 1 << "\n";
    }
  }
}
