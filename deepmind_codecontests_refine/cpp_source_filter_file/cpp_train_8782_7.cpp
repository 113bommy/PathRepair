#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long a[N];
long long b[N];
long long res = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> m;
  long long c;
  for (long long i = 1; i <= m; i++) {
    cin >> b[i];
  }
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  long long cnt = 0;
  long long num = b[1];
  for (long long i = n; i >= 1;) {
    cnt++;
    res += a[i];
    if (cnt == num) {
      cnt = 0;
      i -= num;
    }
    i--;
  }
  cout << res << endl;
  return 0;
}
