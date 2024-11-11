#include <bits/stdc++.h>
using namespace std;
long long n, m, A[500009];
int room[10];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long tc = 1, t = 0, i, j, k, l, r, a, b, c, x;
  cin >> tc;
  while (t++ < tc) {
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) cin >> A[i];
    long long flag = 0;
    for (i = 1; i < n; i++) {
      if (A[i + 1] - A[i] > k) {
        x = A[i + 1] - A[i] - k;
        if (x <= m)
          m -= x;
        else {
          flag = 1;
          break;
        }
      } else {
        m += A[i] - max(A[i + 1] - k, 0LL);
      }
    }
    if (flag)
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
  }
  return 0;
}
