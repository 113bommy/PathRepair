#include <bits/stdc++.h>
using namespace std;
int n, k;
int A[500006];
int ps[500006][20];
bool cmp(int a, int b) { return A[a] > A[b]; }
int que(int l, int r) {
  int t = 31 - __builtin_clz(r - l + 1);
  return cmp(ps[l][t], ps[r - (1 << t) + 1][t]) ? ps[l][t]
                                                : ps[r - (1 << t) + 1][t];
}
vector<int> S[1000006];
int s[500006];
int que(int l, int r, int k) {
  if (l > r) return 0;
  return upper_bound((S[k]).begin(), (S[k]).end(), r) -
         lower_bound((S[k]).begin(), (S[k]).end(), l);
}
int wkr(int l, int r) {
  if (r < l) return 0;
  int pr = que(l, r);
  long long as = 0;
  if (r - pr < pr - l) {
    for (int i = (pr), iend = (r); i <= iend; ++i)
      as += que(l - 1, pr - 1, (s[i] + k - A[pr] % k) % k);
  } else {
    for (int i = (l - 1), iend = (pr - 1); i <= iend; ++i)
      as += que(pr, r, (s[i] + A[pr] % k) % k);
  }
  return as + wkr(l, pr - 1) + wkr(pr + 1, r);
}
void solve() {
  cin >> n >> k;
  S[0].push_back(0);
  for (int i = (1), iend = (n); i <= iend; ++i) {
    scanf("%d", A + i);
    s[i] = (s[i - 1] + A[i]) % k;
    S[s[i] % k].push_back(i);
  }
  for (int i = (1), iend = (n); i <= iend; ++i) {
    ps[i][0] = i;
  }
  for (int k = (1), kend = (19); k <= kend; ++k) {
    for (int i = (1), iend = (n - (1 << k) + 1); i <= iend; ++i) {
      ps[i][k] = cmp(ps[i][k - 1], ps[i + (1 << k - 1)][k - 1])
                     ? ps[i][k - 1]
                     : ps[i + (1 << k - 1)][k - 1];
    }
  }
  cout << wkr(1, n) - n << endl;
}
signed main() { solve(); }
