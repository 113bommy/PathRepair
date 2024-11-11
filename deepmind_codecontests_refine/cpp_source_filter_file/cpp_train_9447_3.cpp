#include <bits/stdc++.h>
using namespace std;
int memo[51][51], n;
long long mask, a[51];
bool can(int st, int k) {
  if (k < 0) return false;
  if (st == n) return k == 0;
  int& ret = memo[st][k];
  if (ret != -1) return ret;
  ret = false;
  long long sum = 0;
  for (int en = st; en < n; en++) {
    sum += a[en];
    if ((sum & mask) == mask) ret |= can(en + 1, k - 1);
  }
  return ret;
}
int main() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  mask = 0;
  for (int i = 49; i >= 0; i--) {
    memset(memo, -1, sizeof memo);
    mask ^= 1LL << i;
    if (!can(0, k)) mask ^= 1LL << i;
  }
  memset(memo, -1, sizeof memo);
  assert(can(0, k));
  cout << mask << endl;
}
