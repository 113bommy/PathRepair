#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
int n, ar[1001];
int dp[1001][1001];
int getAns(int pos, int pre) {
  if (dp[pos][pre] != -1) return dp[pos][pre];
  if (pre > 0) {
    if (pos > n) {
      return ar[pre];
    } else if (pos == n) {
      return max(ar[pre], ar[pos]);
    } else {
      int i = pos;
      int ans = min({max(ar[pre], ar[i]) + getAns(pos + 1, 0),
                     max(ar[pre], ar[i + 1]) + getAns(pos + 2, i),
                     max(ar[i], ar[i + 1]) + getAns(pos + 2, pre)});
      return dp[pos][pre] = ans;
    }
  } else {
    if (pos == n) {
      return ar[pos];
    } else if (pos + 1 == n) {
      return max(ar[pos], ar[pos + 1]);
    } else {
      int i = pos;
      int ans = min({max(ar[i + 1], ar[i]) + getAns(pos + 2, 0),
                     max(ar[i + 2], ar[i + 1]) + getAns(pos + 3, i),
                     max(ar[i], ar[i + 2]) + getAns(pos + 3, i + 1)});
      return dp[pos][pre] = ans;
    }
  }
}
void print(int pos, int pre) {
  if (pre > 0) {
    if (pos > n) {
      cout << pre << '\n';
      return;
    } else if (pos == n) {
      cout << pre << " " << n << '\n';
      return;
    } else {
      int i = pos;
      int res = getAns(pos, pre);
      if (res == max(ar[pre], ar[i]) + getAns(pos + 1, 0)) {
        cout << pre << " " << i << '\n';
        print(pos + 1, 0);
        return;
      }
      if (res == max(ar[pre], ar[i + 1]) + getAns(pos + 2, i)) {
        cout << pre << " " << i + 1 << '\n';
        print(pos + 2, i);
        return;
      }
      if (res == max(ar[i], ar[i + 1]) + getAns(pos + 2, pre)) {
        cout << i << " " << i + 1 << '\n';
        print(pos + 2, pre);
        return;
      }
    }
  } else {
    if (pos == n) {
      cout << n << '\n';
      return;
    } else if (pos + 1 == n) {
      cout << pos << " " << pos + 1 << '\n';
      return;
    } else {
      int i = pos;
      int res = getAns(pos, pre);
      if (res == max(ar[i + 1], ar[i]) + getAns(pos + 2, 0)) {
        cout << i << " " << i + 1 << '\n';
        print(pos + 2, 0);
        return;
      }
      if (res == max(ar[i + 2], ar[i + 1]) + getAns(pos + 3, i)) {
        cout << i + 1 << " " << i + 2 << '\n';
        print(pos + 3, i);
        return;
      }
      if (res == max(ar[i], ar[i + 2]) + getAns(pos + 3, i + 1)) {
        cout << i << " " << i + 2 << '\n';
        print(pos + 3, i + 1);
        return;
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) dp[i][j] = -1;
  }
  cout << getAns(1, 0) << '\n';
  print(1, 0);
}
