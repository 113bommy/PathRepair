#include <bits/stdc++.h>
using namespace std;
stack<int> lf;
int q[12345], val[12345], op[12345], memo[12345][123][2];
bool done[12345][123][2], ispls;
string e;
void parse(int l, int r) {
  if (e[l] == '(') {
    parse(l + 1, q[l] - 1);
    parse(q[l] + 1, r - 1);
    op[l] = op[l + 1] + op[q[l] + 1] + 1;
  } else {
    op[l] = 0;
    val[l] = e[l] - '0';
  }
}
int dp(int v, int x, int type) {
  int pr, mr, l, r, i;
  if (x < 0 || x > op[v]) {
    return ((type) ? ((1 << 30)) : (-(1 << 30)));
  } else if (done[v][x][type]) {
    return memo[v][x][type];
  }
  done[v][x][type] = true;
  memo[v][x][type] = ((type) ? ((1 << 30)) : (-(1 << 30)));
  if (op[v] < x) {
    return memo[v][x][type];
  } else if (op[v] == 0) {
    memo[v][x][type] = val[v];
    return memo[v][x][type];
  }
  l = v + 1;
  r = q[v] + 1;
  if (ispls) {
    pr = x;
    mr = op[v] - x;
    if (pr > 0) {
      pr--;
      if (type) {
        for (i = 0; i <= pr; i++) {
          memo[v][x][type] =
              min(memo[v][x][type], dp(l, i, 1) + dp(r, pr - i, 1));
        }
      } else {
        for (i = 0; i <= pr; i++) {
          memo[v][x][type] =
              max(memo[v][x][type], dp(l, i, 0) + dp(r, pr - i, 0));
        }
      }
      pr++;
    }
    if (mr > 0) {
      if (type) {
        for (i = 0; i <= pr; i++) {
          memo[v][x][type] =
              min(memo[v][x][type], dp(l, i, 1) - dp(r, pr - i, 0));
        }
      } else {
        for (i = 0; i <= pr; i++) {
          memo[v][x][type] =
              max(memo[v][x][type], dp(l, i, 0) - dp(r, pr - i, 1));
        }
      }
    }
  } else {
    pr = op[v] - x;
    mr = x;
    if (pr > 0) {
      if (type) {
        for (i = 0; i <= mr; i++) {
          memo[v][x][type] =
              min(memo[v][x][type], dp(l, i, 1) + dp(r, mr - i, 1));
        }
      } else {
        for (i = 0; i <= mr; i++) {
          memo[v][x][type] =
              max(memo[v][x][type], dp(l, i, 0) + dp(r, mr - i, 0));
        }
      }
    }
    if (mr > 0) {
      mr--;
      if (type) {
        for (i = 0; i < mr; i++) {
          memo[v][x][type] =
              min(memo[v][x][type], dp(l, i, 1) - dp(r, mr - i, 0));
        }
      } else {
        for (i = 0; i < mr; i++) {
          memo[v][x][type] =
              max(memo[v][x][type], dp(l, i, 0) - dp(r, mr - i, 1));
        }
      }
      mr++;
    }
  }
  return memo[v][x][type];
}
int main(void) {
  int i, n, p, m, ans;
  fill(done[0][0], done[12345][0], false);
  cin >> e;
  cin >> p >> m;
  n = e.length();
  for (i = 0; i < n; i++) {
    if (e[i] == '(') {
      lf.push(i);
    } else if (e[i] == '?') {
      q[lf.top()] = i;
      lf.pop();
    }
  }
  ispls = (p <= m);
  parse(0, n - 1);
  ans = dp(0, min(p, m), 0);
  cout << ans << endl;
  return 0;
}
