#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
long long down2(long long x) { return x % 2 ? (x - 1) / 2 : x / 2; }
long long up2(long long x) { return x % 2 ? (x + 1) % 2 : x / 2; }
long long eval(long long x, long long y, long long z, int t) {
  if (t == 0) {
    return x + y + z;
  } else if (t == 1) {
    return -x + y + z;
  } else if (t == 2) {
    return x - y + z;
  } else if (t == 3) {
    return x + y - z;
  } else
    assert(!"Bad value of t");
}
int N;
long long X[MAXN], Y[MAXN], Z[MAXN];
long long val[MAXN][4];
long long lbound[4], rbound[4];
long long ans[3];
bool moo(long long r) {
  for (int p = 0; p < 2; p++) {
    for (int i = 0; i < 4; i++) {
      lbound[i] = LLONG_MIN;
      rbound[i] = LLONG_MAX;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 4; j++) {
        long long lt = up2(-r + val[i][j] - p * (j ? 1 : 3)),
                  rt = down2(r + val[i][j] - p * (j ? 1 : 3));
        lbound[j] = max(lbound[j], lt);
        rbound[j] = min(rbound[j], rt);
      }
    }
    bool bad = false;
    for (int i = 0; i < 4; i++) {
      if (lbound[i] > rbound[i]) {
        bad = true;
        break;
      }
    }
    if (bad || rbound[1] + rbound[2] + rbound[3] < lbound[0] ||
        lbound[1] + lbound[2] + lbound[3] > rbound[0]) {
      continue;
    }
    copy_n(lbound + 1, 3, ans);
    long long diff = max(0ll, lbound[0] - (lbound[1] + lbound[2] + lbound[3]));
    for (int i = 1; i <= 3; i++) {
      long long s = min(diff, rbound[i] - lbound[i]);
      ans[i - 1] += s;
      diff -= s;
    }
    long long nans[3];
    for (int i = 0; i < 3; i++) {
      nans[i] = 2 * ans[i] + p;
    }
    ans[0] = (nans[1] + nans[2]) / 2;
    ans[1] = (nans[0] + nans[2]) / 2;
    ans[2] = (nans[0] + nans[1]) / 2;
    return true;
  }
  return false;
}
void go() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld %lld", &X[i], &Y[i], &Z[i]);
    for (int j = 0; j < 4; j++) {
      val[i][j] = eval(X[i], Y[i], Z[i], j);
    }
  }
  long long lo = -1, hi = 6.1e18;
  while (hi - lo > 1) {
    long long mid = lo + (hi - lo) / 2;
    if (moo(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  moo(hi);
  for (long long a : ans) {
    printf("%lld ", a);
  }
  puts("");
}
int main() {
  int nt;
  for (scanf("%d", &nt); nt--;) {
    go();
  }
}
