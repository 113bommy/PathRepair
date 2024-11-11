#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e5 + 10;
int a[max_n];
int sum[max_n];
int n;
int pre[max_n << 1];
int ma;
int solve1(int num) {
  memset(pre, -1, sizeof(pre));
  int now = 0;
  int res = 0;
  pre[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == ma) {
      now++;
    } else if (a[i] == num) {
      now--;
    }
    if (pre[n + now] != -1) {
      res = max(res, i - pre[n + now]);
    } else {
      pre[n + now] = i;
    }
  }
  return res;
}
int solve2(int num) {
  int res = 0;
  int l = 1;
  memset(sum, 0, sizeof(sum));
  sum[a[l]]++;
  int now = 0;
  if (num == 1) {
    now++;
  }
  for (int i = 2; i <= n; ++i) {
    sum[a[i]]++;
    if (sum[a[i]] == num) {
      now++;
    } else if (sum[a[i]] > num) {
      now--;
      while (sum[a[i]] > num) {
        if (sum[a[l]] == num) {
          now--;
        } else if (sum[a[i]] == num + 1) {
          now++;
        }
        sum[a[l++]]--;
      }
    }
    if (now >= 2) {
      res = max(res, i - l + 1);
    }
  }
  return res;
}
int main() {
  cin >> n;
  int ms = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[a[i]]++;
    if (sum[a[i]] > ms) {
      ms = sum[a[i]];
      ma = a[i];
    }
  }
  int tmp = sqrt(n);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (sum[i] > tmp && i != ma) {
      ans = max(ans, solve1(i));
    }
  }
  for (int i = 1; i <= tmp; ++i) {
    ans = max(ans, solve2(i));
  }
  cout << ans << endl;
  return 0;
}
