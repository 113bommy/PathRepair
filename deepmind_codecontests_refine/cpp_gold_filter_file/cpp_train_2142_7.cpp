#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  long long x = min(a, b);
  long long y = max(a, b);
  if (y > (x + 1) * k)
    cout << "NO"
         << "\n";
  else {
    if (a == b) {
      for (long long i = 0; i < n; i++) {
        if (i % 2)
          cout << "G";
        else
          cout << "B";
      }
    } else {
      if (b > a) {
        long long q = b / (a + 1);
        long long rem = b % (a + 1);
        long long cnt = 1, i = 1;
        while (i <= n) {
          if (rem > 0) {
            while (i <= n && cnt <= q + 1) {
              cout << "B";
              cnt += 1;
              i += 1;
            }
            if (i <= n) {
              cout << "G";
              rem -= 1;
              cnt = 1;
              i += 1;
            } else
              i += 1;
          } else {
            cnt = 1;
            while (i <= n && cnt <= q) {
              cout << "B";
              cnt += 1;
              i += 1;
            }
            if (i <= n) {
              cout << "G";
              i += 1;
              cnt = 1;
              rem -= 1;
            } else
              i += 1;
          }
        }
      } else {
        long long q = a / (b + 1);
        long long rem = a % (b + 1);
        long long cnt = 1;
        long long i = 1;
        while (i <= n) {
          if (rem > 0) {
            while (i <= n && cnt <= q + 1) {
              cout << "G";
              cnt += 1;
              i += 1;
            }
            if (i <= n) {
              cout << "B";
              rem -= 1;
              cnt = 1;
              i += 1;
            } else
              i += 1;
          } else {
            cnt = 1;
            while (i <= n && cnt <= q) {
              cout << "G";
              cnt += 1;
              i += 1;
            }
            if (i <= n) {
              cout << "B";
              i += 1;
              cnt = 1;
              rem -= 1;
            } else
              i += 1;
          }
        }
      }
    }
  }
}
