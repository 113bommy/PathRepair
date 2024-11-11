#include <bits/stdc++.h>
using namespace std;
using INT = long long;
const int NN = 2e5 + 10;
INT x[NN], n;
char s[NN];
INT calc(int L, int R, char xx) {
  INT ans = 0;
  INT pre = s[L];
  for (int i = L + 1; i < R; i++)
    if (s[i] == xx) {
      ans = max(ans, x[i] - pre);
      pre = x[i];
    }
  ans = max(ans, x[R] - pre);
  return x[R] - x[L] - ans;
}
int calc(char xx) {
  int pre = 0;
  INT ans = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == xx) {
      if (pre) ans += x[i] - x[pre];
      pre = i;
    }
  return ans;
}
int pre() {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == 'P') {
      cnt++;
    }
  if (cnt == 0) {
    cout << calc('R') + calc('B') << endl;
    exit(0);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %c", x + i, s + i);
  }
  pre();
  INT ans = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == 'P') {
      for (int j = i + 1; j <= n; j++)
        if (s[j] == 'P') {
          int sr = 0, sb = 0;
          for (int k = i; k <= j; k++) {
            if (s[k] == 'B') sb++;
            if (s[k] == 'R') sr++;
          }
          if (sr + sb == 0) {
            ans += x[j] - x[i];
            break;
          }
          INT tot = 2 * (x[j] - x[i]);
          INT res = x[j] - x[i] + calc(i, j, 'R') + calc(i, j, 'B');
          ans += min(tot, res);
          break;
        }
    }
  for (int i = 1; i <= n; i++)
    if (s[i] == 'P') {
      for (int j = 1; j < i; j++)
        if (s[j] == 'R') {
          ans += x[i] - x[j];
          break;
        }
      for (int j = 1; j < i; j++)
        if (s[j] == 'B') {
          ans += x[i] - x[j];
          break;
        }
      break;
    }
  for (int i = n; i; i--)
    if (s[i] == 'P') {
      for (int j = n; j > i; j--)
        if (s[j] == 'R') {
          ans += x[j] - x[i];
          break;
        }
      for (int j = n; j > i; j--)
        if (s[j] == 'B') {
          ans += x[j] - x[i];
          break;
        }
      break;
    }
  cout << ans << endl;
}
