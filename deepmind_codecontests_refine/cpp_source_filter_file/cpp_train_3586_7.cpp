#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
bool fuck(long long mid) {
  long long ans = 0;
  mid--;
  for (int i = 1; i <= n; i++) ans += min(mid / i, m);
  if (ans < k)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m >> k;
  long long l = 0, r = n * m + 10;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (!fuck(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}
