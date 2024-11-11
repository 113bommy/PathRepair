#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n;
int a[maxn];
int ans[maxn];
bool used[maxn];
int solve(int k) {
  int res = 0;
  for (int i = 0; i < n;) {
    int tot = 0;
    int j = i;
    res++;
    while (j < n) {
      if (tot + (!used[a[j]]) > k) {
        break;
      } else {
        tot += (!used[a[j]]);
        used[a[j]] = true;
        j++;
      }
    }
    while (i < j) {
      used[a[i++]] = false;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int SQ = min(n, int(sqrt(n) + 2));
  for (int i = 1; i <= n; i++) {
    ans[i] = 1e9;
  }
  for (int i = 1; i <= min(n, 1000); i++) {
    ans[i] = solve(i);
  }
  for (int j = 1; j <= min(n, 105); j++) {
    int lo = 0;
    int hi = n;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (solve(mid) > j) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    ans[hi] = min(ans[hi], j);
  }
  for (int i = 2; i <= n; i++) {
    ans[i] = min(ans[i], ans[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
