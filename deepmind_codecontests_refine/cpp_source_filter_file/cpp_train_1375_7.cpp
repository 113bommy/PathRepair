#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100;
const int MAXBITS = 6;
int n;
int a[MAXN];
vector<vector<int>> all;
vector<vector<int>> sorted;
int solve() {
  int x1 = MAXBITS / 2, x2 = MAXBITS - x1;
  all.clear();
  for (int mask = (0); mask < (1 << x1); ++mask) {
    vector<int> diff(n - 1);
    int fst;
    for (int i = (0); i < (n); ++i) {
      int cnt = 0;
      for (int k = (0); k < (x1); ++k) {
        int cur = ((a[i] >> k) ^ (mask >> k)) & 1;
        cnt += cur;
      }
      if (i == 0)
        fst = cnt;
      else
        diff[i - 1] = cnt - fst;
    }
    for (int k = (0); k < (((int)(diff).size())); ++k) diff[k] = -diff[k];
    all.push_back(diff);
  }
  sorted = all;
  sort(sorted.begin(), sorted.end());
  for (int mask = (0); mask < (1 << x2); ++mask) {
    vector<int> diff(n - 1);
    int fst;
    for (int i = (0); i < (n); ++i) {
      int cnt = 0;
      for (int k = (0); k < (x2); ++k) {
        int cur = ((a[i] >> (x1 + k)) ^ (mask >> k)) & 1;
        cnt += cur;
      }
      if (i == 0)
        fst = cnt;
      else
        diff[i - 1] = cnt - fst;
    }
    int idx = lower_bound(sorted.begin(), sorted.end(), diff) - sorted.begin();
    if (idx != ((int)(sorted).size()) && sorted[idx] == diff) {
      int realidx = -1;
      for (int i = (0); i < (((int)(all).size())); ++i)
        if (all[i] == sorted[idx]) {
          realidx = i;
          break;
        }
      assert(realidx != -1);
      return (mask << x1) | realidx;
    }
  }
  return -1;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
