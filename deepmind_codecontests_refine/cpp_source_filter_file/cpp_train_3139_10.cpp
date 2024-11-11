#include <bits/stdc++.h>
using namespace std;
long long H, Sum[200005], tmp, timeKQ, a;
int n, A[200005];
int main() {
  cin >> H >> n;
  timeKQ = 1e17;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    Sum[i] = Sum[i - 1] + A[i];
  }
  for (long long i = 1; i <= n; i++) {
    tmp = H;
    tmp += Sum[i];
    if (tmp <= 0) {
      timeKQ = min(timeKQ, i);
      break;
    } else if (Sum[n] < 0) {
      a = tmp / abs(Sum[n]);
      if (tmp + a * Sum[n] <= 0)
        timeKQ = min(timeKQ, a * n + i);
      else if (tmp + (a + 1) * Sum[n] <= 0)
        timeKQ = min(timeKQ, (a + 1) * n + i);
    }
  }
  if (timeKQ == 1e17)
    cout << -1;
  else
    cout << timeKQ;
  return 0;
}
