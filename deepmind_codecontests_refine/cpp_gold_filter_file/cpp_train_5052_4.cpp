#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e16 + 10;
long long n, k;
map<long long, long long> fen;
long long get(long long v) {
  long long ret = 0;
  for (; v; v -= v & (-v)) ret += fen[v];
  return ret;
}
void add(long long l, long long r) {
  for (; l < MAX; l += l & (-l)) fen[l]++;
  for (; r < MAX; r += r & (-r)) fen[r]--;
}
int main() {
  scanf("%I64d %I64d", &n, &k);
  long long mx = 0;
  while (n--) {
    long long t, v;
    scanf("%I64d %I64d", &t, &v);
    if (get(t) >= k)
      printf("-1 ");
    else {
      printf("%I64d ", max(mx, t) + v);
      add(t, max(mx, t));
      mx = max(mx, t) + v;
    }
  }
  printf("\n");
  return 0;
}
