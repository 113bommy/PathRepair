#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int T;
long long a, b;
bool go(long long x, long long y) {
  if (!x || !y) return false;
  bool res = go(y % x, x);
  if (!res) return true;
  long long bit = y / x % (x + 1);
  if (bit & 1) return false;
  return true;
}
void solve() {
  scanf("%lld%lld", &a, &b);
  if (a > b) swap(a, b);
  bool res = go(a, b);
  if (res)
    puts("First");
  else
    puts("Second");
  return;
}
int main() {
  for (scanf("%d", &T); T--; solve())
    ;
  return 0;
}
