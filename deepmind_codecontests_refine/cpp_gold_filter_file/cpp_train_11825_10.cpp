#include <bits/stdc++.h>
using namespace std;
const int MaxN = 107;
long long N, L, R, a[MaxN], s[MaxN], o[MaxN], ans;
inline long long Calc(long long x) {
  long long sum = 0;
  for (int i = 1; i <= a[0]; i++) {
    if (o[i + 1] + 1 <= x) x -= o[i + 1] + 1, sum += s[i + 1] + a[i];
  }
  return sum;
}
int main() {
  cin >> N >> L >> R;
  while (N) {
    a[++a[0]] = N & 1;
    N >>= 1;
  }
  for (int i = a[0]; i >= 1; i--) {
    s[i] = s[i + 1] + s[i + 1] + a[i];
    o[i] = o[i + 1] + o[i + 1] + 1;
  }
  ans = Calc(R) - Calc(L - 1);
  cout << ans << endl;
  return 0;
}
