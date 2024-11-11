#include <bits/stdc++.h>
using namespace std;
long long l, r;
int ans;
int dig[2][20], v[10], tv[10];
bool dfs2(int now, bool ulim, bool dlim) {
  if (now == 0) {
    return 1;
  }
  if (ulim && dlim) {
    if (dig[0][now] == dig[1][now]) {
      if (tv[dig[0][now]]) {
        --tv[dig[0][now]];
        if (dfs2(now - 1, ulim, dlim)) {
          return 1;
        }
        ++tv[dig[1][now]];
      }
    } else {
      for (int i = dig[0][now] + 1; i < dig[1][now]; ++i) {
        if (tv[i]) {
          return 1;
        }
      }
      if (tv[dig[0][now]]) {
        --tv[dig[0][now]];
        if (dfs2(now - 1, 0, dlim)) {
          return 1;
        }
        ++tv[dig[0][now]];
      }
      if (tv[dig[1][now]]) {
        --tv[dig[1][now]];
        if (dfs2(now - 1, ulim, 0)) {
          return 1;
        }
        ++tv[dig[1][now]];
      }
    }
  } else if (!ulim && !dlim) {
    return 1;
  } else if (ulim && !dlim) {
    for (int i = 0; i < dig[1][now]; ++i) {
      if (tv[i]) {
        return 1;
      }
    }
    if (tv[dig[1][now]]) {
      --tv[dig[1][now]];
      if (dfs2(now - 1, ulim, 0)) {
        return 1;
      }
      ++tv[dig[1][now]];
    }
  } else if (!ulim && dlim) {
    for (int i = dig[0][now] + 1; i < 10; ++i) {
      if (tv[i]) {
        return 1;
      }
    }
    if (tv[dig[0][now]]) {
      --tv[dig[0][now]];
      if (dfs2(now - 1, 0, dlim)) {
        return 1;
      }
      ++tv[dig[0][now]];
    }
  }
  return 0;
}
bool check(int *v) {
  for (int i = 0; i < 10; ++i) {
    tv[i] = v[i];
  }
  return dfs2(18, 1, 1);
}
void solve(int pos, int lft) {
  if (pos == 9) {
    v[9] = lft;
    ans += check(v);
    return;
  }
  for (int i = 0; i <= lft; i++) {
    v[pos] = i;
    solve(pos + 1, lft - i);
  }
}
bool flag = 0;
int main() {
  scanf("%lld%lld", &l, &r);
  if (l == r) {
    puts("1");
    return 0;
  }
  if (r == 1e18) {
    r--;
    flag = 1;
  }
  long long tl = l, tr = r;
  for (int i = 1; i <= 18; i++) dig[1][i] = tr % 10, tr /= 10;
  for (int i = 1; i <= 18; i++) dig[0][i] = tl % 10, tl /= 10;
  solve(0, 18);
  if (flag) {
    memset(v, 0, sizeof(v));
    v[0] = 17;
    v[1] = 1;
    if (check(v)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
