#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n = 0, resLen = 0;
int v[2005], tmp[2005];
vector<string> dp(5005, "0");
int two(int m) {
  memset(tmp, 0, sizeof(tmp));
  tmp[0] = 1;
  int test = m;
  int len = 1;
  while (m) {
    int cur = 0;
    for (int i = 0; i < len; ++i) {
      cur = tmp[i] * 2 + cur;
      tmp[i] = cur % 10;
      cur = cur / 10;
    }
    if (cur) {
      tmp[len] = cur;
      ++len;
    }
    --m;
  }
  return len;
}
void add(int len) {
  int cur = 0;
  resLen = max(resLen, len);
  for (int i = 0; i < resLen; ++i) {
    cur = v[i] + tmp[i] + cur;
    v[i] = cur % 10;
    cur = cur / 10;
  }
  if (cur) {
    v[resLen] = cur;
    ++resLen;
  }
}
void prt(string s) {
  if (s == "0") {
    printf("0\n");
    return;
  }
  int cur = 0, factor = 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '1') {
      add(two(s.size() - i - 1));
    }
  }
  for (int i = resLen - 1; i >= 0; --i) {
    printf("%d", v[i]);
  }
  printf("\n");
  return;
}
bool cmp(string s1, string s2) {
  if (s1.size() > s2.size()) {
    return true;
  } else if (s1.size() == s2.size()) {
    return s1 > s2;
  } else {
    return false;
  }
}
int main() {
  string res = "0";
  ios::sync_with_stdio(false);
  memset(a, 0, sizeof(a));
  memset(v, 0, sizeof(v));
  int x = 0;
  string act;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> act >> x;
    if (act == "sell") {
      a[i] = -x;
    } else {
      a[i] = x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (cmp(dp[i - 1], dp[i])) {
      dp[i] = dp[i - 1];
    }
    if (a[i] >= 0) {
      for (int j = i + 1; j <= n; ++j) {
        if (a[j] + a[i] == 0) {
          int len = dp[i].size();
          int cur = a[i];
          if (len > cur) {
            string tmp(dp[i]);
            tmp[len - cur - 1] = '1';
            if (cmp(tmp, dp[j])) {
              dp[j] = tmp;
            }
          } else {
            string tmp(cur - len + 1, '0');
            tmp[0] = '1';
            tmp += dp[i];
            if (cmp(tmp, dp[j])) {
              dp[j] = tmp;
            }
          }
        }
      }
    }
  }
  prt(dp[n]);
  return 0;
}
