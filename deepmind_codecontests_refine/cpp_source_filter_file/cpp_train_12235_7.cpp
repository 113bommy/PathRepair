#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m = 1000000007) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    int lw = i - 2;
    int hg = n - 2 - i;
    long long temp = 4;
    temp *= power(4, max(lw, 0));
    temp *= power(4, max(hg, 0));
    if (i != 1) temp *= 3;
    if (i != n - 1) temp *= 3;
    ans += temp;
  }
  cout << ans << endl;
}
