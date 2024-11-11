#include <bits/stdc++.h>
using namespace std;
int t, N;
char A[500010];
int last = 0;
int Q[500010];
int tempo(int s) {
  int tLast = N - 1;
  int cnt = s;
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (cnt >= 0 and i > last) {
      tLast = i - 1;
      break;
    }
    Q[i] = 1;
    if (cnt < 0) Q[i]++;
    if (A[i] == 'H')
      cnt--;
    else if (A[i] == 'S')
      cnt++;
    if (cnt < 0) Q[i]++;
    res += Q[i];
  }
  if (cnt < 0) return 1 << 30;
  int res2 = res;
  for (int i = tLast; i >= 0; i--) {
    if (i == tLast)
      res += 1 - Q[i];
    else
      res += 2 - Q[i];
    res2 = min(res2, res);
  }
  return res2;
}
int main() {
  cin >> N >> t;
  cin >> A;
  for (int i = 0; i < N; i++)
    if (A[i] == 'H') last = i;
  int l = 0;
  int r = N + 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (tempo(m) <= t)
      r = m;
    else
      l = m + 1;
  }
  if (l == N + 1)
    cout << -1;
  else
    cout << l;
}
