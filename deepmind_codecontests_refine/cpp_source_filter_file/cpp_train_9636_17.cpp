#include <bits/stdc++.h>
template <class T>
inline void rd(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
using namespace std;
const long long N = 2e5 + 10;
const long long M = 0;
long long li[N], ti[N], r, tot, tag = 0;
vector<long long> ans;
long long deal(long long len, long long limt, long long &tim) {
  if (len <= limt) {
    tim += len;
    return 0;
  }
  long long t = len - limt;
  long long num = t / r, tp = 0;
  if (t % r != 0) {
    tp = r - t % r;
    num++;
  }
  tim += len - 2 * t;
  tot += num;
  if (!tag)
    for (int i = 0; i < num; i++) {
      ans.push_back(tim + r * i);
      if (ans.size() > 1e5) tag = 1;
    }
  tim += t;
  return tp * 2;
}
int main() {
  long long n;
  cin >> n >> r;
  for (int i = 0; i < n; i++) scanf("%I64d", &li[i]), li[i] <<= 1;
  for (int i = 0; i < n; i++) scanf("%I64d", &ti[i]);
  for (int i = 0; i < n; i++)
    if (ti[i] * 2 < li[i]) {
      puts("-1");
      return 0;
    }
  long long lef = 0, tim = 0;
  for (int i = 0; i < n; i++) {
    if (lef >= li[i]) {
      lef -= li[i];
      tim += li[i] / 2;
      continue;
    }
    li[i] -= lef;
    ti[i] -= lef / 2;
    tim += lef / 2;
    lef = deal(li[i], ti[i], tim);
  }
  cout << tot << endl;
  if (tot > 1e5) return 0;
  for (int i = 0; i < tot; i++)
    printf("%d%c", ans[i], i == tot - 1 ? '\n' : ' ');
  return 0;
}
