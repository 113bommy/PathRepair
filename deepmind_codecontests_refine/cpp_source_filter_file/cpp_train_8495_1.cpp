#include <bits/stdc++.h>
using namespace std;
long long n, k, re, sum;
int pr[300005], ti[300005];
priority_queue<pair<int, int> > pq;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) pr[i] = read();
  for (int i = 1; i <= n + k; i++) {
    if (i <= n) {
      pq.push(make_pair(pr[i], i));
      sum += pr[i];
    }
    if (i > k) {
      ti[pq.top().second] = i;
      sum -= pq.top().first;
      pq.pop();
    }
    re += sum;
  }
  printf("%ld\n", re);
  for (int i = 1; i <= n; i++) printf("%d ", ti[i]);
  return 0;
}
