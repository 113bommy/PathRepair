#include <bits/stdc++.h>
using namespace std;
queue<int> q[26];
int n;
long long t[200050], ans;
char s[200050];
void update(int x) {
  while (x <= n) {
    t[x] += 1;
    x += x & (-x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += t[x];
    x -= x & (-x);
  }
  return res;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) q[s[i] - 'a'].push(i);
  for (int i = n - 1; ~i; --i) {
    int tmp = q[s[i] - 'a'].front();
    q[s[i] - 'a'].pop();
    ans += tmp - query(tmp + 1);
    update(tmp + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
