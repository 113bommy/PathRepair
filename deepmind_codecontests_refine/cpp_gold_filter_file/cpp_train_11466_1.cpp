#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[5 * maxn];
int lk[5 * maxn], rk[5 * maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int len = strlen(s);
    stack<char> que;
    int sum = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '(')
        que.push(s[i]);
      else {
        if (!que.empty()) {
          char c = que.top();
          if (c == '(')
            que.pop();
          else
            sum++;
        } else
          sum++;
      }
    }
    int sum1 = que.size();
    if (sum == 0 && sum1 == 0)
      idx++;
    else if (sum1 == 0 && sum != 0) {
      rk[sum]++;
    } else if (sum1 != 0 && sum == 0) {
      lk[sum1]++;
    }
  }
  int ans = 0;
  ans = idx / 2;
  for (int i = 1; i < 5 * maxn; i++) {
    if (rk[i] != 0 && lk[i] != 0) {
      ans += min(rk[i], lk[i]);
    }
  }
  cout << ans;
}
