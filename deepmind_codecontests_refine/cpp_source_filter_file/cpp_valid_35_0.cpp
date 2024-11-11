#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
long long f[N];
void wri(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) wri(x / 10);
  putchar(x % 10 + '0');
}
long long ans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (m < n) {
      cout << "0" << endl;
      continue;
    }
    ans = 0x7ffffff;
    for (int i = 30; i >= 0; i--) {
      long long x = (n >> i) << i;
      long long y = ((m >> i) + 1) << i;
      ans = min(ans, (x ^ y));
    }
    wri(ans);
    puts("");
  }
}
