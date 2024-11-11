#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
inline void fileIO(bool &ptime) {}
const int mxN = 1e6, mxA = 4 * 1e6;
int mxB = 22;
int n;
vector<int> a(mxN + 5), sol(mxN + 5, -1), mask((1 << 22));
void inline SOS() {
  int bit = mxB - 1;
  for (int i = 0; i <= mxA; i++) {
    for (int j = 0; !mask[i] and j <= bit; j++) {
      if ((i & (1 << j))) {
        mask[i] = mask[i ^ (1 << j)];
      }
    }
  }
}
void inline solve(int tt) {
  cin >> n;
  int val = 0;
  for (int i = 0; i < n; i++) cin >> a[i], mask[a[i]] = a[i], val |= a[i];
  for (int i = 28; ~i; i--) {
    if (val & (1 << i)) {
      mxB = i + 1;
      break;
    }
  }
  assert(mxB <= 22);
  SOS();
  for (int i = 0; i < n; i++) {
    if (mask[((1 << mxB) - 1) ^ a[i]]) sol[i] = mask[((1 << mxB) - 1) ^ a[i]];
  }
  for (int i = 0; i < n; i++) cout << sol[i] << " ";
  cout << "\n";
}
int main() {
  srand((unsigned)time(0));
  bool ptime = false;
  fileIO(ptime);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 0, t = 1;
  while (t--) {
    solve(++tt);
  }
  return 0;
}
