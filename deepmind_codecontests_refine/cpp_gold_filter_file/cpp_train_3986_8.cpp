#include <bits/stdc++.h>
using namespace std;
long long k, f[6], q, n, dp1[7][1000005], dp2[7][1000005], tmp, lazy, succ,
    opz[] = {1, 2, 4, 5, 7, 8};
deque<pair<long long, long long> > v;
long long F[6];
long long fortune[10] = {0, 0, 0, 1, 0, 0, 2, 0, 0, 3};
long long ten[6] = {1, 10, 100, 1000, 10000, 100000};
long long query() { return v.front().first; }
void del(long long pos) {
  while (v.size() > 0 && v.front().second <= pos) v.pop_front();
}
void add(long long val, long long pos) {
  while (v.size() > 0 && v.back().first <= val) {
    v.pop_back();
  }
  v.push_back({val, pos});
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < 6; i++) {
    cin >> f[i];
    F[i] = f[i];
  }
  for (int i = 0; i < 1000000; i++) {
    dp1[6][i] = -1000000000000000ll;
  }
  dp1[6][0] = 0;
  tmp = 300000;
  for (long long i = 5; i >= 0; i--) {
    for (long long j = 0; j < tmp; j++) {
      lazy = 0;
      v.clear();
      for (long long z = j; z < 1000000; z += tmp) {
        add(dp1[i + 1][z] - lazy, z);
        dp1[i][z] = query() + lazy;
        del(z - (k - 1) * 3ll * tmp);
        lazy += f[i];
      }
    }
    tmp /= 10;
  }
  for (int d = 0; d <= 5; d++) {
    for (int i = 999999; i >= 0; i--) {
      for (int b = 1; b <= 9; b++) {
        int pre = i - ten[d] * b;
        if (pre < 0) break;
        dp1[0][i] = max(dp1[0][i], dp1[0][pre] + fortune[b] * F[d]);
      }
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n;
    cout << dp1[0][n] << "\n";
  }
  return 0;
}
