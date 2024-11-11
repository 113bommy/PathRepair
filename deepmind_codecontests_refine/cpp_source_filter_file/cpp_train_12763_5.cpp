#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long INFF = 1e18;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
int n, per[MAX];
int cnt[MAX << 1];
int main(void) {
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", per + i);
  int ans = 0;
  long long val = 0;
  for (int i = (1); i < (n + 1); ++i) val += abs(per[i] - i);
  for (int i = (1); i < (n + 1); ++i) cnt[per[i] - i + n]++;
  long long cur = val, num = 0;
  for (int i = (1); i < (n + 1); ++i)
    if (per[i] > i) num++;
  for (int i = (1); i < (n); ++i) {
    int bk = n + 1 - i;
    cnt[per[bk] - bk + n]--;
    if (per[bk] - bk + 1 - i > 0) num--;
    cur = cur - num + n - 1 - num;
    cur = cur - abs(per[bk] - bk + 1 - i) + abs(per[bk] - 1);
    num -= cnt[i + n];
    if (per[bk] > 1) num++;
    cnt[per[bk] + n + i]++;
    if (cur < val) {
      val = cur, ans = i;
    }
  }
  printf("%lld %d\n", val, ans);
  return 0;
}
