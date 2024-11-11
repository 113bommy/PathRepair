#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
struct Node {
  int pos;
  long long val;
  inline bool operator<(const Node &a) const {
    if (val == a.val) return pos < a.pos;
    return val > a.val;
  }
};
priority_queue<Node> q;
long long a[400305];
int main() {
  int n = read();
  int k = read();
  int x = read();
  long long minn = 1e9 + 1, pos = 0;
  int num = 0, num0 = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (minn > abs(a[i])) {
      minn = abs(a[i]);
      pos = i;
    }
    if (a[i] < 0) {
      num++;
    }
    if (a[i] == 0) num0++;
  }
  int flag = num % 2;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      if (!flag && num % 2 == 0) {
        a[i] = -x;
        flag = 1;
        num = 1;
      } else {
        a[i] = x;
      }
      k--;
      if (k == 0) break;
    }
  }
  minn = 1e9, pos = 0;
  for (int i = 1; i <= n; i++) {
    if (minn > abs(a[i])) {
      minn = abs(a[i]);
      pos = i;
    }
  }
  if (num % 2 == 1) {
    for (int i = 1; i <= n; i++) {
      q.push((Node){i, abs(a[i])});
    }
    for (int i = 1; i <= k; i++) {
      Node u = q.top();
      q.pop();
      u.val += x;
      if (a[u.pos] > 0)
        a[u.pos] = u.val;
      else
        a[u.pos] = -u.val;
      q.push(u);
    }
    for (int i = 1; i <= n; i++) {
      printf("%lld ", a[i]);
    }
    return 0;
  }
  if (minn > 1ll * k * x) {
    minn -= 1ll * k * x;
    if (a[pos] < 0) minn = -minn;
    a[pos] = minn;
    for (int i = 1; i <= n; i++) {
      printf("%lld ", a[i]);
    }
    return 0;
  }
  while (k > 0) {
    minn -= x;
    k--;
    if (minn < 0) break;
  }
  if (minn == 0 && k == 0) {
    a[pos] = 0;
    for (int i = 1; i <= n; i++) {
      printf("%lld ", a[i]);
    }
    return 0;
  }
  if (a[pos] > 0)
    a[pos] = minn;
  else
    a[pos] = -minn;
  for (int i = 1; i <= n; i++) {
    q.push((Node){i, abs(a[i])});
  }
  for (int i = 1; i <= k; i++) {
    Node u = q.top();
    q.pop();
    u.val += x;
    if (a[u.pos] > 0)
      a[u.pos] = u.val;
    else
      a[u.pos] = -u.val;
    q.push(u);
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", a[i]);
  }
  return 0;
}
