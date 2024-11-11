#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long ctrl(long long x) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += min(m, x / i);
  }
  return cnt;
}
long long BS(long long bas, long long son) {
  if (bas + 1 >= son) {
    if (ctrl(bas) >= k)
      return bas;
    else
      return son;
  }
  long long ort = (bas + son) / 2;
  if (ctrl(ort) < k)
    return BS(ort + 1, son);
  else
    return BS(bas, ort);
}
int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  cout << BS(1LL, 250000000000LL) << endl;
  return 0;
}
