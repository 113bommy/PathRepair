#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1e5 + 4;
inline int FIX(int a) { return (a % Mod + Mod) % Mod; }
int x[128], msk[128], a[128];
long long k[128], dp[(1 << 20) + 5];
void update(long long &det, long long v) {
  if (det == -1)
    det = v;
  else
    det = min(det, v);
}
int main() {
  ios::sync_with_stdio(0);
  int n, m, b;
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> k[i];
    int tmp, curm = 0;
    cin >> tmp;
    for (int j = 0; j < tmp; j++) {
      int x;
      cin >> x;
      x--;
      curm += (1 << (x));
    }
    msk[i] = curm;
    a[i] = i;
  }
  sort(a, a + n, [](const int &A, const int &B) { return k[A] < k[B]; });
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  long long res = -1;
  for (int i = 0; i < n; i++) {
    int idx = a[i];
    for (int j = 0; j < (1 << (m)); j++) {
      if (dp[j] == -1) continue;
      update(dp[j | msk[i]], dp[j] + x[idx]);
    }
    if (dp[(1 << (m)) - 1] != -1) {
      update(res, dp[(1 << (m)) - 1] + k[idx] * b);
    }
  }
  cout << res << endl;
  return 0;
}
