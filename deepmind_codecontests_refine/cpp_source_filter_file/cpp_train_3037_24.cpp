#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n, q;
int a[N], s[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) s[i] = s[i - 1] + a[i];
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (s[r] - s[l - 1]) / 10 << endl;
  }
}
