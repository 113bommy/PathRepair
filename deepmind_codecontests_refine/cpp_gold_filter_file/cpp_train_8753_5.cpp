#include <bits/stdc++.h>
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
long long n, m, s;
long long a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  if ((n - 1) * m < s || m > s)
    cout << "NO\n";
  else {
    cout << "YES\n";
    long long ave = s / m;
    long long p = (s - ave * m);
    int now = 1;
    for (int i = 1; i <= m; i++) {
      if (p) {
        if (now + ave + 1 <= n)
          now += ave + 1;
        else
          now -= ave + 1;
        p--;
      } else {
        if (now + ave <= n)
          now += ave;
        else
          now -= ave;
      }
      cout << now << " ";
    }
  }
  return 0;
}
