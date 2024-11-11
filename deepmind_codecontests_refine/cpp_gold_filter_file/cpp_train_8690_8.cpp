#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, z;
int ar[100005], ans[100005];
int freq[100005];
void solve() {
  cin >> n;
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      cout << l++ << ' ';
    } else {
      cout << r-- << " ";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
}
