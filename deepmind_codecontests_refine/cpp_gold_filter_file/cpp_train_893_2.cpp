#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int num_l[N + 1], num_r[N + 1];
int cnt[10], c[10];
int ans;
bool flag = false;
bool Go(int pos, bool flag_l, bool flag_r) {
  if (pos > N) return true;
  int L = num_l[pos], R = num_r[pos];
  if (flag_l && flag_r) {
    if (L > R) return false;
    if (L == R) {
      if (c[L]) {
        --c[L];
        bool res = Go(pos + 1, 1, 1);
        ++c[L];
        return res;
      }
      return false;
    }
    for (int i = L + 1; i < R; ++i) {
      if (c[i]) return true;
    }
    if (c[L]) {
      --c[L];
      if (Go(pos + 1, 1, 0)) {
        ++c[L];
        return true;
      }
      ++c[L];
    }
    if (c[R]) {
      --c[R];
      if (Go(pos + 1, 0, 1)) {
        ++c[R];
        return true;
      }
      ++c[R];
    }
    return false;
  }
  if (flag_l) {
    for (int i = L + 1; i <= 9; ++i) {
      if (c[i]) return true;
    }
    if (c[L]) {
      --c[L];
      bool res = Go(pos + 1, 1, 0);
      ++c[L];
      return res;
    }
    return false;
  }
  if (flag_r) {
    for (int i = 0; i < R; ++i) {
      if (c[i]) return true;
    }
    if (c[R]) {
      --c[R];
      bool res = Go(pos + 1, 0, 1);
      ++c[R];
      return res;
    }
    return false;
  }
}
long long L, R;
int CNT = 0;
void Find_Number(int k, int last) {
  if (k > N) {
    ++CNT;
    if (CNT == 38) flag = true;
    bool res = Go(1, true, true);
    flag = false;
    ans += res;
    return;
  }
  for (int i = last; i <= 9; ++i) {
    ++c[i];
    Find_Number(k + 1, i);
    --c[i];
  }
}
int main() {
  scanf("%I64d%I64d", &L, &R);
  if (L == R) {
    puts("1");
    return 0;
  }
  ans = 0;
  if (R == 1e18) {
    ans = L > 1e17;
    --R;
  }
  for (int i = N; i; --i) {
    num_l[i] = L % 10;
    L /= 10;
    num_r[i] = R % 10;
    R /= 10;
  }
  Find_Number(1, 0);
  printf("%d\n", ans);
  return 0;
}
