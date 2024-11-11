#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
int T, n;
int a[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int r = 0;
  int l = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != a[1]) r = i;
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != a[n]) l = i;
  }
  cout << max(n - l, r - 1) << endl;
  return 0;
}
