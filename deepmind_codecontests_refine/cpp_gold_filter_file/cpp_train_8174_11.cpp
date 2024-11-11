#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
int n;
int a[1 << 17];
int b[1 << 17];
int Q[1 << 18];
int can[1 << 17];
int Min(int L, int R) {
  int res = inf;
  for (L += n, R += n; L < R; L >>= 1, R >>= 1) {
    if (L & 1) res = min(res, Q[L++]);
    if (R & 1) res = min(res, Q[--R]);
  }
  return res;
}
void add(int x, int val) {
  Q[n + x] = val;
  for (int i = x; i; i >>= 1) Q[i] = min(Q[i], val);
}
int main() {
  memset(can, 0, sizeof(can));
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  if (n == 1) {
    cout << "1\n1" << endl;
    return 0;
  }
  Q[n] = 0;
  for (int i = 1; i < n; ++i) Q[n + i] = Q[n + i - 1] + a[i - 1] - b[i - 1];
  Q[n] = Q[2 * n - 1] + a[n - 1] - b[n - 1];
  for (int i = n - 1; i; --i) Q[i] = min(Q[2 * i], Q[2 * i + 1]);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    can[i] |= (Min(0, n) - cur) >= 0;
    cur += a[i] - b[i];
    add(i,
        Q[n + ((i - 1) + n) % n] + a[((i - 1) + n) % n] - b[((i - 1) + n) % n]);
  }
  cur = 0;
  Q[2 * n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) Q[n + i] = Q[n + i + 1] + a[i + 1] - b[i];
  Q[2 * n - 1] = Q[n] + a[0] - b[n - 1];
  for (int i = n - 1; i; --i) Q[i] = min(Q[2 * i], Q[2 * i + 1]);
  for (int i = n - 1; i >= 0; --i) {
    can[i] |= (Min(0, n) - cur) >= 0;
    cur += a[i] - b[(n + i - 1) % n];
    add(i, Q[n + ((i + 1) + n) % n] + a[(i + 1) % n] - b[i]);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) res += can[i];
  cout << res << endl;
  for (int i = 0; i < n; ++i)
    if (can[i]) cout << i + 1 << " ";
  cout << endl;
  return 0;
}
