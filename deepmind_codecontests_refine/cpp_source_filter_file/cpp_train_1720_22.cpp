#include <bits/stdc++.h>
const int OO = 0x3f3f3f3f;
using namespace std;
void fastt();
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int sizee = 1e6;
long long N[sizee];
int main() {
  fastt();
  long long n;
  cin >> n;
  long long L = 0, R = 1e7, m = 0;
  long long Y = 0;
  while (L <= R) {
    m = (L + R) >> 1;
    long long O = ((long long)m * (m + 1)) / 2;
    if (O > n)
      R = m - 1;
    else if (O == n) {
      cout << m << endl;
      return 0;
    } else if (n > O) {
      Y = m;
      L = m + 1;
    }
  }
  cout << n - ((long long)Y * (Y + 1)) / 2 << endl;
  return 0;
}
void fastt() { ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); }
