#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 300000;
const int MAXQ = 300000;
int n, nq;
char s[MAXN + 1];
int ql[MAXQ], qr[MAXQ];
vector<int> qans[MAXQ];
int sum[MAXN + 1];
void solve() {
  sum[0] = 0;
  for (int i = (0); i < (n); ++i)
    sum[i + 1] = sum[i] + (i % 2 == 0 ? +1 : -1) * (s[i] == '+' ? +1 : -1);
  int lo = 0, hi = 0;
  for (int i = (0); i <= (n); ++i) lo = min(lo, sum[i]), hi = max(hi, sum[i]);
  vector<vector<int>> pos(hi - lo + 1);
  for (int i = (0); i <= (n); ++i) pos[sum[i] - lo].push_back(i);
  for (int i = (0); i < (nq); ++i) {
    int l = ql[i], r = qr[i];
    int len = r - l + 1;
    int diff = sum[r + 1] - sum[l];
    if (diff == 0) {
      qans[i] = vector<int>(0);
      continue;
    }
    qans[i] = vector<int>(len % 2 == 0 ? 2 : 1, -1);
  }
}
void run() {
  scanf("%d%d", &n, &nq);
  scanf("%s", s);
  for (int i = (0); i < (nq); ++i)
    scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
  solve();
  for (int i = (0); i < (nq); ++i) {
    printf("%d\n", ((int)(qans[i]).size()));
  }
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
