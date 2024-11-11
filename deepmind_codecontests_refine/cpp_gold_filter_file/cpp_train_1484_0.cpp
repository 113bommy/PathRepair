#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double PI = acos(-1.0);
const int MAXN = 200000 + 7;
int f[MAXN][20];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    auto cp = a[i];
    for (int j = 2; j * j <= cp; j++) {
      int k = 0;
      while (cp % j == 0) {
        cp /= j;
        k++;
        f[j][k]++;
      }
    }
    if (cp > 1) {
      f[cp][1]++;
    }
  }
  long long answer = 1;
  for (int i = 2; i < MAXN; i++) {
    long cur_mp = 1;
    for (int j = 1; j < 20; j++) {
      if (f[i][j] >= n - 1) {
        cur_mp *= 1ll * i;
      } else {
        answer *= cur_mp;
        break;
      }
    }
  }
  cout << answer << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
