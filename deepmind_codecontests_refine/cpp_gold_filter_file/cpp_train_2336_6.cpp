#include <bits/stdc++.h>
using namespace std;
struct person {
  long long money, monitor, prob;
  bool operator<(const person& p) const { return monitor < p.monitor; }
};
person all[102];
int n, m, b;
const int LIM = (1 << 20);
long long memo[2][LIM + 2];
long long DP() {
  memset((memo), (0x3f), sizeof(memo));
  memo[0][(1 << m) - 1] = memo[1][(1 << m) - 1] = 0;
  long long res = 1LL << 60;
  for (int i = 0; i < n; i++) {
    for (int msk = (1 << m) - 1; msk >= 0; msk--) {
      long long c1 = memo[(i + 1) & 1][msk];
      long long c2 = all[i].money + memo[(i + 1) & 1][msk | all[i].prob];
      memo[i & 1][msk] = min(c1, c2);
    }
    res = min(res, memo[i & 1][0] + all[i].monitor * b);
  }
  return res >= 1LL << 60 ? -1 : res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> all[i].money >> all[i].monitor >> c;
    all[i].prob = 0;
    while (c--) {
      int x;
      cin >> x;
      all[i].prob |= 1 << (x - 1);
    }
  }
  sort(all, all + n);
  long long res = DP();
  cout << res << "\n";
  return 0;
}
