#include <bits/stdc++.h>
using namespace std;
int N, S;
long long s[100010], a[100010], b[100010];
int idx[100010];
int wh[100010];
long long r1, r2;
long long res;
bool cmp1(int aa, int bb) {
  if (a[aa] - b[aa] < a[bb] - b[bb])
    return true;
  else
    return false;
}
void solve() {
  int i;
  long long s1 = 0, s2 = 0;
  for (i = 0; i < N; i++) {
    if (a[i] > b[i]) {
      s1 += s[i];
      r1 += s[i] * a[i];
      wh[i] = 1;
    } else {
      r2 += s[i] * b[i];
      s2 += s[i];
      wh[i] = 2;
    }
  }
  long long tmp;
  long long ts1, ts2;
  long long tr1, tr2;
  if (s1 % S + s2 % S <= S) {
    for (i = 0; i < N; i++) {
      idx[i] = i;
    }
    sort(idx, idx + N, cmp1);
    ts1 = s1, ts2 = s2;
    tr1 = r1, tr2 = r2;
    for (i = 0; i < N; i++) {
      if (wh[idx[i]] == 1) {
        if (s1 % S <= s[idx[i]]) {
          tmp = s1 % S;
          s1 -= tmp;
          s2 += tmp;
          r1 -= tmp * a[idx[i]];
          r2 += tmp * b[idx[i]];
          break;
        } else {
          tmp = s[idx[i]];
          s1 -= tmp;
          s2 += tmp;
          r1 -= tmp * a[idx[i]];
          r2 += tmp * b[idx[i]];
        }
      }
    }
    res = r1 + r2;
    s1 = ts1, s2 = ts2;
    r1 = tr1, r2 = tr2;
    for (i = N - 1; i >= 0; i--) {
      if (wh[idx[i]] == 2) {
        if (s2 % S <= s[idx[i]]) {
          tmp = s2 % S;
          s2 -= tmp;
          s1 -= tmp;
          r2 -= tmp * b[idx[i]];
          r1 += tmp * a[idx[i]];
          break;
        } else {
          tmp = s[idx[i]];
          s2 -= tmp;
          s1 += tmp;
          r2 -= tmp * b[idx[i]];
          r1 += tmp * a[idx[i]];
        }
      }
    }
    if (res < r1 + r2) res = r1 + r2;
  } else
    res = r1 + r2;
  printf("%I64d\n", res);
}
int main() {
  int i;
  scanf("%d%d", &N, &S);
  for (i = 0; i < N; i++) scanf("%I64d %I64d %I64d", &s[i], &a[i], &b[i]);
  solve();
  return 0;
}
