#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int fen[100005];
long long sortedval[100005], val[100005];
long long r[100005];
inline void incr(int ind) {
  while (ind < 100005) {
    fen[ind]++;
    ind += (ind & (-ind));
  }
}
inline void decr(int ind) {
  while (ind < 100005) {
    fen[ind]--;
    ind += (ind & (-ind));
  }
}
inline int sum(int ind) {
  int res = 0;
  while (ind > 0) {
    res += fen[ind];
    ind -= (ind & (-ind));
  }
  return res;
}
inline void clearfen() {
  for (int i = 0; i < 100005; i++) {
    fen[i] = 0;
  }
}
inline void incrall() {
  for (int i = 1; i <= n; i++) {
    incr(i);
  }
}
inline void precomp() {
  for (int i = 1; i <= n; i++) {
    val[i] = val[i - 1] + r[i - 1];
    sortedval[i] = val[i];
  }
  sort(sortedval + 1, sortedval + n + 1);
}
inline bool chk(long long value) {
  long long cnt = 0;
  clearfen();
  incrall();
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      decr(lower_bound(sortedval + 1, sortedval + n + 1, val[i]) - sortedval);
    }
    cnt += (n - i -
            sum(lower_bound(sortedval + 1, sortedval + n + 1, val[i] + value) -
                sortedval - 1));
  }
  return cnt >= k;
}
inline long long binarysearch() {
  precomp();
  long long le = -1000000000;
  le *= 1000000000;
  long long ri = 1000000000;
  ri *= 1000000000;
  long long mi;
  while (le + 1 < ri) {
    mi = (le + ri) / 2;
    if (chk(mi)) {
      le = mi;
    } else {
      ri = mi;
    }
  }
  return le;
}
int main() {
  scanf("%d %I64d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &r[i]);
  }
  printf("%I64d\n", binarysearch());
  return 0;
}
