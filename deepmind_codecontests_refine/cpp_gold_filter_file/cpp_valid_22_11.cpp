#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e1 + 10, MOD = 998244353;
int n, k;
vector<int> a[MAXN];
long long mask[MAXN], choose_masks[MAXN][MAXN];
bool bad() {
  cout << "REJECTED\n";
  exit(0);
}
void rec(int c, long long chosen, long long unchosen) {
  if (c == k) {
    if (unchosen) bad();
    for (int i = 0; i < n - 1; i++)
      if (((chosen >> i) & 1) && ((chosen >> (i + 1)) & 1 ^ 1)) bad();
    return;
  }
  int tot = __builtin_popcountll(mask[c]);
  int ones = __builtin_popcountll(chosen & mask[c]);
  int zeroes = __builtin_popcountll((~unchosen) & mask[c]) - ones;
  long long next_unchosen = unchosen & (~mask[c]);
  for (int new_zeroes = zeroes; tot - new_zeroes >= ones; new_zeroes++) {
    long long next_chosen = (chosen & (~mask[c])) | choose_masks[c][new_zeroes];
    rec(c + 1, next_chosen, next_unchosen);
  }
}
void solve() {
  cin >> n >> k;
  if (n == 1) {
    cout << "ACCEPTED\n";
    return;
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    a[i].resize(x);
    for (auto& c : a[i]) cin >> c, --c, mask[i] |= 1ll << c;
    for (int zeroes = 0; zeroes <= x; zeroes++) {
      long long me = 0;
      for (int j = zeroes; j < x; j++) me |= 1ll << a[i][j];
      choose_masks[i][zeroes] = me;
    }
  }
  rec(0, 0, (1ll << n) - 1);
  cout << "ACCEPTED\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
}
