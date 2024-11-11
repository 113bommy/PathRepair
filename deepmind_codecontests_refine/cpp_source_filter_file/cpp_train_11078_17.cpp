#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int inf32 = 1e9 + 9;
const long long inf64 = 1e18 + 18;
const int N = 5e5 + 5;
const long long mod = 1e9 + 7;
bitset<N> bits;
void solve() {
  int n, d, a, ans = 0;
  scanf("%d%d", &n, &d);
  bits[0] = true;
  while (n--) {
    scanf("%d", &a);
    bits |= (bits << a);
  }
  int nxt;
  for (int i = 0; i < N; ++ans) {
    nxt = i;
    for (int j = i + 1; j <= i + d; ++j) {
      if (bits[j]) nxt = j;
    }
    if (nxt == i) break;
    i = nxt;
  }
  printf("%d %d", nxt, ans);
}
int main() {
  solve();
  return 0;
}
