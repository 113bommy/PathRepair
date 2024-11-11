#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, pair<long long, int> > bank;
pair<long long, int> getDP(long long v, int mx) {
  if (v <= 0) return make_pair(0, 0);
  if (v < 10) return make_pair(1, max((long long)0, mx - v));
  pair<long long, int> state = make_pair(v, mx);
  if (bank.find(state) != bank.end()) return bank[state];
  long long moveCount = 0;
  long long base = 1;
  while (base <= v / 10) base *= 10;
  while (true) {
    int firstDigit = (int)(v / base);
    int newMax = max(mx, firstDigit);
    pair<long long, int> cur = getDP(v % base, newMax);
    moveCount += cur.first;
    v -= v % base;
    if (cur.second > 0)
      v -= cur.second;
    else {
      v -= newMax;
      if (newMax > 0) moveCount++;
    }
    if (firstDigit == 0) break;
  }
  pair<long long, int> ret = make_pair(moveCount, -v);
  bank[state] = ret;
  return ret;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  pair<long long, int> ans = getDP(n, 0);
  printf("%I64d", ans.first);
  return 0;
}
