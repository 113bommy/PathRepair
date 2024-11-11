#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
int a, b, c, n, cnt;
char str[200];
priority_queue<int, vector<int>, greater<int> > q1, q2;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &n);
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d%s", &d, str);
    if (strcmp(str, "USB") == 0)
      q1.push(d);
    else if (strcmp(str, "PS/2") == 0)
      q2.push(d);
  }
  long long sum = 0;
  int cnt = 0;
  while ((a || b || c) && (!q1.empty() || !q2.empty())) {
    if (!q1.empty() && !q2.empty()) {
      if (q1.top() < q2.top()) {
        int d = q1.top();
        q1.pop();
        if (a || c) {
          sum += d;
          ++cnt;
          if (a)
            --a;
          else if (c)
            --c;
        }
      } else if (q1.top() > q2.top()) {
        int d = q2.top();
        q2.pop();
        if (b || c) {
          if (b)
            --b;
          else if (c)
            --c;
          sum += d;
          ++cnt;
        }
      } else {
        if (a > b) {
          int d = q2.top();
          q2.pop();
          if (b || c) {
            if (b)
              --b;
            else if (c)
              --c;
            sum += d;
            ++cnt;
          }
        } else {
          int d = q1.top();
          q1.pop();
          if (a || c) {
            if (b)
              --b;
            else if (c)
              --c;
            sum += d;
            ++cnt;
          }
        }
      }
      continue;
    }
    if (!q1.empty()) {
      int d = q1.top();
      q1.pop();
      if (a || c) {
        ++cnt;
        sum += d;
        if (a)
          --a;
        else if (c)
          --c;
      }
      continue;
    }
    if (!q2.empty()) {
      int d = q2.top();
      q2.pop();
      if (b || c) {
        ++cnt;
        sum += d;
        if (b)
          --b;
        else if (c)
          --c;
      }
    }
  }
  printf("%d %lld\n", cnt, sum);
  return 0;
}
