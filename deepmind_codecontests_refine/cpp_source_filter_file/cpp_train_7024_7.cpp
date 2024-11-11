#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
const int N = 200005;
const double eps = 1e-9;
long long a[N];
int main() {
  long long n;
  cin >> n;
  char ch;
  for (long long i = 1; i <= n; ++i) {
    cin >> ch;
    if (ch == 'A') a[1]++;
    if (ch == 'C') a[2]++;
    if (ch == 'G') a[3]++;
    if (ch == 'T') a[4]++;
  }
  long long mx = 0, ans = 0;
  for (long long i = 1; i <= 4; ++i) {
    if (a[i] > mx)
      ans = 1, a[i] = mx;
    else if (a[i] == mx)
      ans++;
  }
  long long rec = 1;
  while (n >= 1) {
    if (n % 2 == 1) (rec *= ans) %= 1000000007;
    n /= 2;
    (ans *= ans) %= 1000000007;
  }
  cout << rec;
  return 0;
}
