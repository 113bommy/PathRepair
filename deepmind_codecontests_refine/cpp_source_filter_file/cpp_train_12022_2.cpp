#include <bits/stdc++.h>
using namespace std;
namespace stuff {
const int MOD = 1000000007;
void solve(int test_num) {
  int N;
  cin >> N;
  vector<int> lef(N), rig(N);
  vector<double> cnt(N);
  for (int i = 0; i < N; i++) cin >> lef[i] >> rig[i];
  for (int i = 0; i < N; i++) cnt[i] = rig[i] - lef[i] + 1;
  double res = 0.0;
  for (int mask = 1; mask < (1 << N); mask++) {
    const int bit_cnt = __builtin_popcount(mask);
    if (1 < bit_cnt) {
      for (int x = 1; x <= 10000; x++) {
        bool ok = true;
        for (int i = 0; i < N; i++)
          if ((1 << i & mask) && (x < lef[i] || x > rig[i])) ok = false;
        if (ok) {
          double pr = 1.0;
          for (int i = 0; i < N; i++)
            if (1 << i & mask) pr *= 1 / cnt[i];
          for (int i = 0; i < N; i++)
            if (1 << i & ~mask)
              pr *= max(0, min(rig[i] + 1, x) - lef[i]) / cnt[i];
          res += pr * x;
        }
      }
    }
    for (int x = 1; x <= 10000; x++) {
      bool ok = true;
      for (int i = 0; i < N; i++)
        if ((1 << i & mask) && (x < lef[i] || x > rig[i])) ok = false;
      if (ok) {
        for (int i = 0; i < N; i++) {
          if ((1 << i & mask) || x >= rig[i]) continue;
          double pr = (rig[i] - max(x, lef[i] - 1)) / cnt[i];
          for (int j = 0; j < N; j++)
            if (1 << j & mask) pr *= 1 / cnt[j];
          for (int j = 0; j < N; j++)
            if (i != j && (1 << j & ~mask))
              pr *= max(0, min(rig[j] + 1, x) - lef[j]) / cnt[j];
          res += pr * x;
        }
      }
    }
  }
  cout << setprecision(9) << res << endl;
}
void solve() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int t = 1; t <= T; t++) solve(t);
}
}  // namespace stuff
int main() {
  stuff::solve();
  return 0;
}
