#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, LOG = 70;
int n, power[LOG], between[LOG], extra[LOG], ende[LOG], t[LOG];
long long mx[maxn];
vector<long long> other;
bool check(int x) {
  int cur = x;
  memcpy(t, power, sizeof(t));
  for (int i = 0; i < LOG - 1; i++) {
    for (int j = 0; j < cur; j++) mx[j] = 1LL << i;
    t[i] -= cur;
    cur = min(cur, power[i + 1]);
  }
  int ptr = LOG - 1, ptr2 = other.size() - 1;
  while (ptr >= 0 && t[ptr] <= 0) ptr--;
  for (int i = 0; i < x; i++) {
    if (ptr < 0 && ptr2 < 0) continue;
    long long curMax;
    if (ptr < 0) {
      curMax = other[ptr2];
      if (curMax > (mx[i] * 2))
        return false;
      else
        ptr2--;
    } else if (ptr2 < 0) {
      curMax = 1LL << ptr;
      if (curMax > (mx[i] * 2))
        return false;
      else {
        t[ptr]--;
        while (ptr >= 0 && t[ptr] <= 0) ptr--;
      }
    } else {
      if ((1LL << ptr) > other[ptr2]) {
        curMax = 1LL << ptr;
        if (curMax > (mx[i] * 2))
          return false;
        else {
          t[ptr]--;
          while (ptr >= 0 && t[ptr] <= 0) ptr--;
        }
      } else {
        curMax = other[ptr2];
        if (curMax > (mx[i] * 2))
          return false;
        else
          ptr2--;
      }
    }
  }
  return (ptr < 0 && ptr2 < 0);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x, X;
    scanf("%lld", &x);
    X = x;
    int cur = 0;
    bool good = true;
    while (x > 1) {
      if (x & 1) good = false;
      x >>= 1;
      cur++;
    }
    if (good)
      power[cur]++;
    else
      between[cur]++, other.push_back(X);
  }
  sort(other.begin(), other.end());
  int l = 1, r = power[0];
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m))
      r = m - 1;
    else
      l = m + 1;
  }
  if (power[0] != 0 && check(l)) {
    for (int i = l; i <= power[0]; i++) printf("%d ", i);
  } else {
    printf("-1\n");
  }
  return 0;
}
