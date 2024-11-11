#include <bits/stdc++.h>
using namespace std;
inline bool eq(double a, double b) { return fabs(a - b) < 1e-9; }
const long long int inf = 1e15;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
int n, mi, mj, ms;
int ar[200002];
int dp[200002];
void set_max(int i, int j) {
  if (j - i + 1 > ms) {
    ms = j - i + 1;
    mi = i;
    mj = j;
  }
}
void fast_frwd(int& i, int k) {
  while (i <= k) {
    dp[ar[i]]--;
    i++;
  }
  i--;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> ar[i];
  sort(ar, ar + n);
  int k = 0;
  for (int i = 0, j = 0; i < n;) {
    if (j >= n) break;
    dp[ar[i]]++;
    for (j = i + 1; j < n;) {
      dp[ar[j]]++;
      if (ar[j] - ar[j - 1] <= 1) {
        if (dp[ar[j]] < 2 && ar[j] != ar[j + 1]) {
          set_max(i, j);
          fast_frwd(i, j);
          break;
        } else {
          set_max(i, j);
        }
        j++;
      } else {
        fast_frwd(i, j);
        break;
      }
    }
  }
  if (ms == 0) {
    cout << ms << endl;
    cout << ar[0] << endl;
    return 0;
  }
  cout << ms << endl;
  for (int i = mi; i <= mj; i += 2) {
    cout << ar[i] << " ";
  }
  for (int k = (ms & 1 ? mj - 1 : mj); k > mi; k -= 2) {
    cout << ar[k] << " ";
  }
  cout << endl;
  return 0;
}
